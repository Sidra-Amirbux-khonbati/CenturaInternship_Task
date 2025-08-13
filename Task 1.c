#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Record {
    char name[100];
    char writer[100];
    char code[100];
};

struct Record shelf[MAX_BOOKS];
int bookCount = 0;

void loadData();
void saveData();
void addBook();
void deleteBook();
void searchBook();
void displayBooks();

void addBook() {
    if (bookCount < MAX_BOOKS) {
        printf("\n--- Add a Book ---\n");

        printf("Enter book title: ");
        scanf(" %[^\n]", shelf[bookCount].name);

        printf("Enter author name: ");
        scanf(" %[^\n]", shelf[bookCount].writer);

        printf("Enter ISBN code: ");
        scanf(" %[^\n]", shelf[bookCount].code);

        bookCount++;
        printf("Book successfully added!\n");
    } else {
        printf("\nLibrary is full! Cannot add more.\n");
    }
}

void searchBook() {
    char searchTitle[100];
    int found = 0;
    int i;

    printf("\nEnter book title to search: ");
    scanf(" %[^\n]", searchTitle);

	for(i = 0; i < bookCount; i++){
        if (strcmp(shelf[i].name, searchTitle) == 0) {
            printf("\nBook Found:\n");
            printf("Title  : %s\n", shelf[i].name);
            printf("Author : %s\n", shelf[i].writer);
            printf("ISBN   : %s\n", shelf[i].code);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No such book found in the library.\n");
    }
}

void deleteBook() {
    char removeTitle[100];
    int found = 0;
    int i , j;

    printf("\nEnter book title to delete: ");
    scanf(" %[^\n]", removeTitle);

    for (i = 0; i < bookCount; i++) {
        if (strcmp(shelf[i].name, removeTitle) == 0) {
            for (j = i; j < bookCount - 1; j++) {
                shelf[j] = shelf[j + 1];
            }
            bookCount--;
            found = 1;
            printf("Book removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Book not found. Unable to delete.\n");
    }
}

void saveData() {
	int i;
    FILE *fp = fopen("library_records.txt", "w");
    if (fp == NULL) {
        printf("Error while saving data!\n");
        return;
    }

    for (i = 0; i < bookCount; i++) {
        fprintf(fp, "%s\n%s\n%s\n", shelf[i].name, shelf[i].writer, shelf[i].code);
    }

    fclose(fp);
}

void loadData() {
    FILE *fp = fopen("library_records.txt", "r");
    if (fp == NULL) {
        return;
    }

    while (fgets(shelf[bookCount].name, sizeof(shelf[bookCount].name), fp)) {
        shelf[bookCount].name[strcspn(shelf[bookCount].name, "\n")] = '\0';

        if (!fgets(shelf[bookCount].writer, sizeof(shelf[bookCount].writer), fp)) break;
        shelf[bookCount].writer[strcspn(shelf[bookCount].writer, "\n")] = '\0';

        if (!fgets(shelf[bookCount].code, sizeof(shelf[bookCount].code), fp)) break;
        shelf[bookCount].code[strcspn(shelf[bookCount].code, "\n")] = '\0';

        bookCount++;
    }

    fclose(fp);
}

void displayBooks() {
	int i;
    if (bookCount == 0) {
        printf("\nLibrary is empty! Please add some books.\n");
    } else {
        printf("\n--- All Books in Library ---\n");

        for (i = 0; i < bookCount; i++) {
            printf("\nBook %d:\n", i + 1);
            printf("Title : %s\n", shelf[i].name);
            printf("Author: %s\n", shelf[i].writer);
            printf("ISBN  : %s\n", shelf[i].code);
        }
        printf("Total Books: %d\n", bookCount);
    }
}


int main() {
    int option;

    loadData();
    printf("\tSIMPLE LIBRARY MANAGER TOOL\t\n");
    do {
        printf("\n==== Main Menu ====\n");
        printf("1. Add New Book\n");
        printf("2. Delete Book by Title\n");
        printf("3. Search Book by Title\n");
        printf("4. Show All Books\n");
        printf("5. Save & Exit\n");

		printf("Select an option from the menu (1-5) and press Enter: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                addBook();
                break;
            case 2:
                deleteBook();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                saveData();
                printf("Exiting... All records saved.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (option != 5);

    return 0;
}



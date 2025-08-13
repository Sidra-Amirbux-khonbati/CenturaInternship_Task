#include <stdio.h>
#include <string.h>
#include <ctype.h>

void doEncrypt(char plain[], char key[], char out[]) {
	int pos;
    int pLen = strlen(plain);
    int kLen = strlen(key);
    for (pos = 0; pos < pLen; pos++) {
        if (isalpha(plain[pos])) {
            char ref = isupper(plain[pos]) ? 'A' : 'a';
            out[pos] = ((plain[pos] - ref) + (tolower(key[pos % kLen]) - 'a')) % 26 + ref;
        } else {
            out[pos] = plain[pos];
        }
    }
    out[pLen] = '\0';
}

void doDecrypt(char coded[], char key[], char out[]) {
	int pos;
    int cLen = strlen(coded);
    int kLen = strlen(key);
    for (pos = 0; pos < cLen; pos++) {
        if (isalpha(coded[pos])) {
            char ref = isupper(coded[pos]) ? 'A' : 'a';
            out[pos] = ((coded[pos] - ref) - (tolower(key[pos % kLen]) - 'a') + 26) % 26 + ref;
        } else {
            out[pos] = coded[pos];
        }
    }
    out[cLen] = '\0';
}

int main() {
    char plainText[200], keyWord[50], cipherText[200], originalText[200];

    printf("\tVigenere Cipher Encryption Tool\t\n");

    printf("Enter Key: ");
    scanf("%s", keyWord);
    getchar();

    printf("Enter Text: ");
    fgets(plainText, sizeof(plainText), stdin);
    plainText[strcspn(plainText, "\n")] = '\0';

    doEncrypt(plainText, keyWord, cipherText);
    printf("\n*** Encryption Process Completed ***\n");
    printf("Input Text     : %s\n", plainText);
    printf("Key Applied    : %s\n", keyWord);
    printf("Encrypted Form : %s\n", cipherText);

    doDecrypt(cipherText, keyWord, originalText);
    printf("\n*** Decryption Process Completed ***\n");
    printf("Recovered Text : %s\n", originalText);

    return 0;
}


#include <stdio.h>
#include <math.h>

void solveQuadratic(float a, float b, float c) {
    float discriminant = b * b - 4 * a * c;
    
	printf("\tSolving Quadratic Equation\t\n");
	
	printf("Equation: %.2fx^2 = (%.2f)x + %.2f = 0\n", a, b, c);
	printf("Discriminant = %.2f\n", discriminant);
	
    if (discriminant > 0) {
        float root1 = (-b + sqrt(discriminant)) / (2 * a);
        float root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are Real and different.\n");
        printf("Two real roots: %.2f and %.2f\n", root1, root2);
    } else if (discriminant == 0) {
        float root = -b / (2 * a);
        printf("Roots are real and equal.\n");
        printf("One real root: %.2f\n", root);
    } else {
        float realPart = -b / (2 * a);
        float imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are imaginary (complex).\n");
        printf("Complex roots: %.2f + %.2fi and %.2f - %.2fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }
}

int main() {
    float a, b, c;

    printf("Enter coefficients a, b, and c for the quadratic equation (ax^2 + bx + c = 0):\n");
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c);

    if (a == 0) {
        printf("This is not a quadratic equation, as 'a' cannot be zero.\n");
    } else {
        solveQuadratic(a, b, c);
    }

    return 0;
}


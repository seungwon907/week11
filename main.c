#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include "polynomial.h"

void parseAndFill(polynomial* p, char* str) {
    int c, e;
    char* ptr = str;
    while (sscanf(ptr, "%dX^%d", &c, &e) == 2) {
        elementType item = { c, e };
        addItemPolynomial(p, item);
        ptr = strchr(ptr, '+');
        if (!ptr) break;
        ptr++;
    }
}

int main() {
    char input1[100], input2[100];
    polynomial* A = createPolynomial(10);
    polynomial* B = createPolynomial(10);

    printf("다항식 1 (예: 3X^2+2X^1+1X^0): ");
    scanf("%s", input1);
    parseAndFill(A, input1);

    printf("다항식 2 (예: 1X^1+2X^0): ");
    scanf("%s", input2);
    parseAndFill(B, input2);

    printf("A: "); printPolynomial(A);
    printf("B: "); printPolynomial(B);

    polynomial* result = timePolynomial(A, B);
    printf("AxB 결과: ");
    printPolynomial(result);

    return 0;
}
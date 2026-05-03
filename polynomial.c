#include "polynomial.h"
#include <string.h>

polynomial* createPolynomial(int capacity) {
    return createArrayList(capacity);
}

polynomial* addItemPolynomial(polynomial* po, elementType item) {
    for (int i = 0; i < po->size; i++) {
        if (po->data[i].expo == item.expo) {
            po->data[i].coef += item.coef;
            return po;
        }
    }
    insertArrayList(po, po->size, item);
    return po;
}

void printPolynomial(polynomial* po) {
    for (int i = 0; i < po->size; i++) {
        if (po->data[i].coef == 0) continue;
        printf("%dX^%d", po->data[i].coef, po->data[i].expo);
        if (i < po->size - 1 && po->data[i + 1].coef > 0) printf("+");
    }
    printf("\n");
}

// 다항식 곱셈: A의 모든 항 * B의 모든 항
polynomial* timePolynomial(polynomial* p1, polynomial* p2) {
    polynomial* result = createPolynomial(p1->size * p2->size);

    for (int i = 0; i < p1->size; i++) {
        for (int j = 0; j < p2->size; j++) {
            elementType newItem;
            newItem.coef = p1->data[i].coef * p2->data[j].coef;
            newItem.expo = p1->data[i].expo + p2->data[j].expo;
            addItemPolynomial(result, newItem);
        }
    }
    return result;
}
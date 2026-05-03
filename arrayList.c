#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

// 府胶飘 积己
arrayList* createArrayList(int size) {
    arrayList* al = (arrayList*)malloc(sizeof(arrayList));
    if (al == NULL) return NULL;

    al->data = (elementArrayList*)malloc(sizeof(elementArrayList) * size);
    if (al->data == NULL) {
        free(al);
        return NULL;
    }
    al->size = 0;
    al->capacity = size;

    return al;
}

// 府胶飘 家戈
void destroyArrayList(arrayList* al) {
    if (al) {
        free(al->data);
        free(al);
    }
}

int isEmptyArrayList(arrayList* al) {
    return al->size == 0;
}

int isFullArrayList(arrayList* al) {
    return al->size == al->capacity;
}

int sizeArrayList(arrayList* al) {
    return al->size;
}

int insertArrayList(arrayList* al, int pos, elementArrayList item) {
    if (pos < 0 || pos > al->size) {
        return 0;
    }

    if (isFullArrayList(al)) {
        int newCapacity = al->capacity * 2;
        elementArrayList* newData = (elementArrayList*)realloc(al->data, sizeof(elementArrayList) * newCapacity);
        if (newData == NULL) return 0;
        al->data = newData;
        al->capacity = newCapacity;
    }


    for (int i = al->size; i > pos; i--) {
        al->data[i] = al->data[i - 1];
    }

    al->data[pos] = item;
    al->size++;

    return 1;
}

elementArrayList deleteArrayList(arrayList* al, int pos) {
    if (pos < 0 || pos >= al->size) {
        elementArrayList empty = { 0, 0 };
        return empty;
    }

    elementArrayList item = al->data[pos];

    for (int i = pos; i < al->size - 1; i++) {
        al->data[i] = al->data[i + 1];
    }

    al->size--;
    return item;
}


int initArrayList(arrayList* al) {
    al->size = 0; 
    return 1;
}

elementArrayList getItemArrayList(arrayList* al, int pos) {
    if (pos < 0 || pos >= al->size) {
        elementArrayList empty = { 0, 0 };
        return empty;
    }
    return al->data[pos];
}

int replaceItemArrayList(arrayList* al, int pos, elementArrayList item) {
    if (pos < 0 || pos >= al->size) {
        return 0;
    }
    al->data[pos] = item;
    return 1;
}

void printArrayList(arrayList* al) {
    for (int i = 0; i < al->size; i++) {
        printf("%dX^%d", al->data[i].coef, al->data[i].expo);
        if (i < al->size - 1) printf(" + ");
    }
    printf("\n");
}
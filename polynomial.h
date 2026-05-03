#include "arrayList.h"

typedef arrayList polynomial;



extern polynomial* createPolynomial(int capacity);
extern polynomial* addItemPolynomial(polynomial* po, elementType item);
extern void printPolynomial(polynomial* po);
extern polynomial* addPolynomial(polynomial* p1,polynomial* p2);
extern polynomial* timePolynomial(polynomial* p1,polynomial* p2);

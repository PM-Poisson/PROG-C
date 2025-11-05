#include "operator.h"

int somme(int a, int b) {
    return a + b;
}

int difference(int a, int b) {
    return a - b;
}

int produit(int a, int b) {
    return a * b;
}

int quotient(int a, int b) {
    if (b != 0) return a / b;
    return 0; // éviter la division par zéro
}

int modulo(int a, int b) {
    if (b != 0) return a % b;
    return 0;
}

int et_logique(int a, int b) {
    return a & b;
}

int ou_logique(int a, int b) {
    return a | b;
}

int negation(int a) {
    return ~a;
}

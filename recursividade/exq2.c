#include <stdio.h>

void imprime(int n);
void imprimeDec(int n);

int main () {
    imprime(5);
    printf("\n");
    imprimeDec(5);
}

void imprime(int n) {
if ( n == 0) return;
    imprime (n-1);
    printf ( "%d ", n);
}

void imprimeDec(int n) {
    printf( "%d ", n);
    if (n == 1) return;
    imprimeDec(n-1);
}
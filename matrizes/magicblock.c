#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main () {
    int n;
    scanf("%d", &n);

    int* M = (int*)calloc(n * n, sizeof(int));
    int linhaAtual = 0;
    int colunaAtual = n/2;
    int indiceLinear;

    int valor;
    for (valor = 1; valor <= n*n; valor ++){
       indiceLinear = n*linhaAtual + colunaAtual;

       M[indiceLinear] = valor;

       int proxLinha = linhaAtual - 1;
       int proxColuna = colunaAtual - 1;

       if (proxLinha < 0) {
        proxLinha = n - 1;
       }
       if (proxColuna < 0) {
        proxColuna = n - 1;
       }

       if (M[n*proxLinha + proxColuna] != 0) {
        linhaAtual = linhaAtual+1 % n;
       }
       else {
        linhaAtual = proxLinha;
        colunaAtual = proxColuna;
       }
    }
    
    int p;
    for (p = 0; p <= (n*n)-1; p++){
        printf("%d", M[p]);
        if ((p + 1) % n == 0) {
            printf("\n");
        }
        else {
            printf(" ");
        }
    }

    free(M);
    return 0;
}
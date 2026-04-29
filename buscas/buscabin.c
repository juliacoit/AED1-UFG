#include <stdio.h>
#include <math.h>

#define NMAX 200000

int buscaBin(int valor, int * vet, int tam);

int main () {
    int N, Q;
    scanf("%d%d", &N, &Q);
    int vet[NMAX];
    for (int i = 0; i < N; i++){
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < Q; i++){
        int x;
        scanf("%d", &x);
        int achou = buscaBin(x, vet, N);
        printf("%d\n", achou);
    }
}

int buscaBin(int valor, int * vet, int tam){
    int inicio = 0;
    int fim = tam - 1;
    while (inicio <= fim) {
        int meio = inicio + ((fim - inicio) >> 1);
        if (valor == vet[meio]) {
            return 1;
        }
        else {
            if (valor < vet[meio]) {
                fim = meio - 1;
            }
            else {
                inicio = meio + 1;
            }
        }
    }
    return 0;
}
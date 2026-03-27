#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    long long int ind;
    long long int val;
} mat_spr;

void insere (mat_spr *M, int i, int *n, long long int v);
void consul (mat_spr *M, int i, int n, long long int *v);
int lugar (mat_spr *M, int i, int n);
void compacta(mat_spr *M, int i, int *n);
void atrib(mat_spr *M, int i, int *n, long long int v);

int main () {

int op;
int inicio = 0;
int n = 0;

scanf("%d", &op);

mat_spr * M = (mat_spr*)calloc(op, sizeof(mat_spr));
if (M == NULL) return 1; // alocar dinamicamente o tamanho maximo para o numero de entradas, que podem ser todas de insercao

while (inicio < op){
    inicio++;
    char type;
    long long int i;
    long long int x;

    scanf(" %c", &type);

    if (type == 'A'){
        scanf("%lld", &i);
        scanf("%lld", &x);

        atrib(M, i, &n, x);

    }
    if (type == 'C'){
        long long int valorConsul = 0;
        scanf("%lld", &i);
        consul(M, i, n, &valorConsul);

        printf("%lld\n", valorConsul);
    }
}
    free(M);
    return 0;
}

void insere(mat_spr *M, int i, int *n, long long int v){
    int j = 0, k = 0;

    while (j < *n && M[j].ind < i) j++;

    for (k = *n; k > j; k--){
        M[k] = M[k - 1];
    }

    M[j].ind = i;
    M[j].val = v;
    (*n)++;
}

int lugar(mat_spr *M, int i, int n) {
    int j = 0, pos = -1;

    for (j = 0; j < n; j++){
        if (M[j].ind == i)
        pos = j;
    }
    return pos;
}


void consul(mat_spr *M, int i, int n, long long int *v){
   int j = 0;
   
   if (i < 0){
    printf("Indice invalido!");
    exit( EXIT_FAILURE );
   }

   j = lugar(M, i, n);
   if (j == -1) {
    *v = 0.0;
   }
   else {
    *v = M[j].val;
   }

}

void compacta(mat_spr *M, int i, int *n){
    int j = 0;

    for (j = i; j < *n-1; j++){
       M[j] = M[j + 1]; 
    }

    M[*n-1].ind = -1; M[*n-1].val = 0.0;
    (*n)--;
}

void atrib(mat_spr *M, int i, int *n, long long int v){
    int j = 0;
   
   if (i < 0){
    printf("Indice invalido!");
    exit( EXIT_FAILURE );
   }

   j = lugar(M, i, *n);
   if (j == -1){
    if (v != 0) {
        insere(M, i, n, v);
    }
   }
   else {
    if (v == 0.0) {
        compacta (M, j, n);
    }
    else
        M[j].val = v;
   }
}
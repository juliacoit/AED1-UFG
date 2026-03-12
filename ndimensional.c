#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main () {
    int k; // numero de dimensoes
    int t = 1;
    scanf("%d", &k);

    int * S = (int*)calloc(k, sizeof(int));
    int i;
    for (i = 0; i < k; i++){
        scanf("%d", &S[i]); // os tamanhos
        t = t*S[i]; // total de elementos
    }
    int *M = (int*)calloc(t, sizeof(int)); // matriz linear que guarda os valores
    for (i = 0; i < t; i++){
        scanf("%d", &M[i]);
    }

    int Q;
    int cont = 0;
    scanf("%d", &Q);

    while (cont < Q){
        char type;
        scanf(" %c", &type);

        if (type == 'A') {
            long long int k_linear = 0;
            int dimInd;

            for (i = 0; i < k; i++){
                scanf("%d", &dimInd);
                k_linear = (k_linear * S[i]) + dimInd; // 
            }
            scanf("%d", &M[k_linear]);
        }
        cont++;
    }
    for (i = 0; i < t; i++){
        printf("%d", M[i]);
        if ((i + 1) % S[k-1] == 0) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    free(S);
    free(M);
    
    return 0;
}
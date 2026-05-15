#include <stdio.h>

int saddleback(int mat[][1000], int N, int x);

int mat[1000][1000];

int main () {
    int N, Q;
    scanf("%d %d", &N, &Q);

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
        scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < Q; i++){
        int x;
        scanf("%d", &x);

        printf("%d\n", saddleback(mat, N, x));

    }
}

int saddleback(int mat[][1000], int N, int x){
    int linha = 0;
    int coluna = N-1;

    while (linha < N && coluna >=0) {
        if (x == mat[linha][coluna]){
            return 1;
        }
        else {
            if (x < mat[linha][coluna]) {
                coluna--;
            }
            else {
                linha++;
            }
        }
    }
    return 0;
}
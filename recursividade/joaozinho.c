#include <stdio.h>

int i, j;
int L[8][8];
int visitado[8][8];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int recur(int x, int y, int N);

int main () {
    int N;
    scanf("%d", &N);
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            scanf("%d", &L[i][j]);
        }
    }

    if (L[0][0] == 0 || L[N-1][N-1] == 0) {
        printf("0\n");
    } else {
        printf("%d\n", recur(0, 0, N));
    }
    return 0;
}

int recur(int x, int y, int N){
    int i, nx, ny;

     if (x == N -1 && y == N -1) {
        return 1;
    }

    visitado[x][y] = 1;

    for (i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];

        if ((nx >= 0 && nx <= N-1) && (ny >= 0 && ny <= N-1)) {
            
            if (L[nx][ny] == 1 && visitado[nx][ny] == 0){
                recur(nx, ny, N);
                return 1;
                }
            }
        }
    }
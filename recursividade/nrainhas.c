#include <stdio.h>
#include <stdlib.h>

void popula(int irainha, int jrainha, int n, int add, int ** tabuleiro);
int recur(int i, int n, int ** tabuleiro);

int main () {
    int N;
    scanf("%d", &N);

    int ** tabuleiro = (int**)calloc(N, sizeof(int*));

    for (int i = 0; i < N; i++) {
    tabuleiro[i] = calloc(N, sizeof(int));
    }
    
    int vzs = recur(0, N, tabuleiro);
    printf("%d", vzs);

    for (int i = 0; i < N; i++) {
    free(tabuleiro[i]);
}
}

void popula(int irainha, int jrainha, int n, int add, int ** tabuleiro){
    // essa funcao vai percorrer o tabuleiro e marca-lo
    // 0 -> livre
    // -1 -> rainha
    // >0 -> ataque

    for(int ii = 0; ii < n; ii++){
        for(int jj = 0; jj < n; jj++){
            if(irainha == ii && jrainha == jj)
                continue;
            if(irainha == ii)
                tabuleiro[ii][jj]+=add;
            else if (jrainha == jj)
                tabuleiro[ii][jj]+=add;
            else if(irainha-ii == jrainha-jj)
                tabuleiro[ii][jj]+=add;
            else if(irainha-ii == jj-jrainha)
                tabuleiro[ii][jj]+=add;
        }
    }
}

int recur(int i, int n, int ** tabuleiro) {
    if (i == n) {
        // aqui chegamos na ultima linha completa, caso base
        return 1;
    }

    int total = 0;

    for (int j = 0; j < n; j++) {
         if (tabuleiro[i][j] == 0){ // esta vazio
            tabuleiro[i][j] = -1;
            popula(i, j, n, 1, tabuleiro);

            // backtrack
            total += recur(i+1, n, tabuleiro); // ele vai entrar e repetir o processo ate dar erro (e nao entrar no if)

            // caso de erro
            tabuleiro[i][j] = 0;
            popula(i, j, n, -1, tabuleiro);

         }
    }
    return total;
}


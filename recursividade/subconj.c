#include <stdio.h>

const int N = 20;
int A[N];
int choose[N];

int busca(int i, int soma, int n, int T){
    if(soma == T) {
        return 1;
    }
    if(i == n) {
        return 0;
    }
    choose[i] = 1;
    if(busca(i+1, soma+A[i], n, T)) return 1;
}

int main(){
    int n, T;
    scanf("%d %d", &n, &T);

    for (int i = 0; i< n; i++){
        scanf("%d", &A[i]);
    }
    if (busca(0, 0, n, T) == 1) {
        int aux = 0;
        for(int i = 0; i < n; i++)
            if(choose[i]){
                
            }
    }
    return 0;
}
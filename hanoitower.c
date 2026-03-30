#include <stdio.h>

void hanoi(int n, int inicio, int aux, int final);

int main () {

}

void hanoi(int n, int inicio, int aux, int final){
    if (n == 1) {
        printf("Movendo de %c para %c\n", inicio, final);
        return;
    }
    hanoi(n-1, inicio, final, aux);
    printf("Movendo de %c para %c\n", inicio, final);
    hanoi(n-1, )
}
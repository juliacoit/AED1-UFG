#include <stdio.h>

void hanoi(int n, char inicio, char aux, char final);

int main () {
    int n_disks = 3;
    hanoi(n_disks, 'A', 'B', 'C');
}

void hanoi(int n, char inicio, char aux, char final){
    if (n == 1) {
        printf("Movendo disco 1 de %c para %c\n", inicio, final);
        return;
    }
    hanoi(n-1, inicio, final, aux);
    printf("Movendo disco %d de %c para %c\n",n , inicio, final);
    hanoi(n-1, aux, inicio, final);
}
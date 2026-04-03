#include <stdio.h>

// função auxiliar pra indentação visual
void indent(int nivel) {
    for (int i = 0; i < nivel; i++) {
        printf("  "); // dois espaços por nível
    }
}

void hanoi(int n, char inicio, char aux, char final, int nivel);

int main () {
    int n_disks = 3;
    hanoi(n_disks, 'A', 'B', 'C', 0);
    return 0;
}

void hanoi(int n, char inicio, char aux, char final, int nivel){

    indent(nivel);
    printf("Entrando: hanoi(%d, %c, %c, %c)\n", n, inicio, aux, final);

    if (n == 1) {
        indent(nivel);
        printf("Move disco 1: %c para %c\n", inicio, final);

        indent(nivel);
        printf("Saindo: hanoi(%d, %c, %c, %c)\n", n, inicio, aux, final);
        return;
    }

    // primeira chamada recursiva
    hanoi(n-1, inicio, final, aux, nivel + 1);

    indent(nivel);
    printf("Move disco %d: %c para %c\n", n, inicio, final);

    // segunda chamada recursiva
    hanoi(n-1, aux, inicio, final, nivel + 1);

    indent(nivel);
    printf("Saindo: hanoi(%d, %c, %c, %c)\n", n, inicio, aux, final);
}
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

/*
hanoi(3, A, B, C) chamada da funcao
│
├── hanoi(2, A, C, B) -> hanoi(n-1, inicio, final, aux)
│   │
│   ├── hanoi(1, A, B, C) hanoi(n-1, inicio, final, aux), entrou de novo, funcoes recursivas chamam elas mesmas ate cair no caso base
│   │   → move 1: A → C 
│   │   if (n == 1) {
    |   printf("Movendo disco 1 de %c para %c\n", inicio, final);
    |    return;
    |}
│   ├── move 2: A → B depois do return, "voltou" uma função e executou printf("Movendo disco %d de %c para %c\n",n , inicio, final);
│   │
│   └── hanoi(1, C, A, B) hanoi(n-1, aux, inicio, final);
│       → move 1: C → B aqui caiu no caso base de novo
│
├── move 3: A → C
│
└── hanoi(2, B, A, C)
    │
    ├── hanoi(1, B, C, A)
    │   → move 1: B → A
    │
    ├── move 2: B → C
    │
    └── hanoi(1, A, B, C)
        → move 1: A → C
*/
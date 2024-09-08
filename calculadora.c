#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Funcoes para realizar as operacoes basicas */
float adicionar(float a, float b) {
    return a + b;
}

float subtrair(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    if (b == 0) {
        printf("Erro: Divisao por zero nao e permitida.\n");
        exit(EXIT_FAILURE);
    }
    return a / b;
}

/* Funcao para exibir o menu e obter a escolha do usuario */
int menu() {
    int escolha;

    printf("Escolha uma operacao:\n");
    printf("1. Adicao\n");
    printf("2. Subtracao\n");
    printf("3. Multiplicacao\n");
    printf("4. Divisao\n");
    printf("5. Sair\n");
    printf("Digite sua escolha (1-5): ");
    
    while (1) {
        if (scanf("%d", &escolha) == 1 && escolha >= 1 && escolha <= 5) {
            // Limpar o buffer de entrada
            while (getchar() != '\n');
            break;
        } else {
            printf("Entrada invalida. Digite um numero entre 1 e 5: ");
            // Limpar o buffer de entrada
            while (getchar() != '\n');
        }
    }

    return escolha;
}

/* Funcao para verificar se a entrada e um numero valido */
int verificar_numero(float *num) {
    char buffer[100];
    char *endptr;
    
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        *num = strtof(buffer, &endptr);
        // Verifica se toda a string foi convertida para numero
        return *endptr == '\0' || *endptr == '\n';
    }
    return 0;
}

/* Funcao principal */
int main() {
    int escolha;
    float num1, num2;
    float resultado;
    char continuar;

    while (1) {
        escolha = menu();

        if (escolha == 5) {
            printf("Saindo...\n");
            break;
        }

        printf("Digite o primeiro numero: ");
        while (1) {
            if (verificar_numero(&num1)) {
                break;
            }
            printf("Entrada invalida. Digite um numero valido: ");
        }

        printf("Digite o segundo numero: ");
        while (1) {
            if (verificar_numero(&num2)) {
                break;
            }
            printf("Entrada invalida. Digite um numero valido: ");
        }

        switch (escolha) {
            case 1:
                resultado = adicionar(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                break;
            case 2:
                resultado = subtrair(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                break;
            case 3:
                resultado = multiplicar(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                break;
            case 4:
                resultado = dividir(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                break;
        }

        printf("Deseja fazer outro calculo? (s/n): ");
        while (1) {
            if (scanf(" %c", &continuar) == 1 && (continuar == 's' || continuar == 'n')) {
                // Limpar o buffer de entrada
                while (getchar() != '\n');
                break;
            } else {
                printf("Entrada invalida. Digite 's' para sim ou 'n' para nao: ");
                // Limpar o buffer de entrada
                while (getchar() != '\n');
            }
        }

        if (continuar == 'n') {
            printf("Saindo...\n");
            break;
        }
    }

    return 0;
}


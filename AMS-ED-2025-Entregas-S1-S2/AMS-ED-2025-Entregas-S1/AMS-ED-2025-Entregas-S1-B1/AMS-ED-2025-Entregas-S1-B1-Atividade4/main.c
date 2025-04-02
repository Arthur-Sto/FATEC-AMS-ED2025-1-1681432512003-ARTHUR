/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: Manipulacao de Pilha                    */
/*             Objetivo: fazer calculadora com rpn e pilhas                         */
/*                                                                                  */
/*                                  Autor: Arthur Amaral Santos                     */
/*                                                                   Data:30/03/2025*/
/*----------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PILHA 100

typedef int tipo_base; 

typedef struct Pilha {
    tipo_base dados[MAX_PILHA];
    int topo;
} Pilha;


Pilha *criar_pilha() {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = -1; 
    return p;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}


int cheia(Pilha *p) {
    return p->topo == MAX_PILHA - 1;
}


void push(Pilha *p, tipo_base dado) {
    if (cheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->dados[++(p->topo)] = dado;
}


tipo_base pop(Pilha *p) {
    if (vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1; 
    }
    return p->dados[(p->topo)--];
}


tipo_base top(Pilha *p) {
    if (vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1; 
    }
    return p->dados[p->topo];
}


void calcular(char *Valores[], int numValores) {
    Pilha *p = criar_pilha();

    for (int i = 0; i < numValores; i++) {
        
        int num = atoi(Valores[i]);
    
        if (num != 0 || strcmp(Valores[i], "0") == 0) {
            push(p, num);
        }
        else {
            if (vazia(p)) {
                printf("Erro: falta de operandos suficientes para a operação.\n");
                return;
            }

            int num2 = pop(p);
            int num1 = pop(p);

            int resultado;
            char operador = Valores[i][0]; 

            
            switch (operador) {
                case '+':
                    resultado = num1 + num2;
                    break;
                case '-':
                    resultado = num1 - num2;
                    break;
                case '*':
                    resultado = num1 * num2;
                    break;
                case '/':
                    if (num2 != 0) {
                        resultado = num1 / num2;
                    } else {
                        printf("Erro: divisão por zero.\n");
                        return;
                    }
                    break;
                default:
                    printf("Operador inválido: %c\n", operador);
                    return;
            }

            
            push(p, resultado);
        }
    }

    
    if (!vazia(p)) {
        printf("Resultado final: %d\n", top(p));
    } else {
        printf("Erro: pilha vazia após cálculo.\n");
    }

    free(p);  
}

int main() {
    char Notacao[100]; 

    printf("Digite a notacao a ser calculada (exemplo: 5 3 + 2 *): ");
    fgets(Notacao, sizeof(Notacao), stdin);
    Notacao[strcspn(Notacao, "\n")] = 0; // Remover a nova linha do final da string

    printf("Você digitou: %s\n", Notacao);
    
    char *Delim = " "; 
    char *Valores[100]; 
    int i = 0;
    char *separacoes = strtok(Notacao, Delim);
    
    while (separacoes && i < 100) {
        Valores[i++] = separacoes;
        separacoes = strtok(NULL, Delim);
    }

    calcular(Valores, i);  
    
    return 0;
}



/*----------------------------------------------------------------------------------*/
/*   FATEC-SC#o Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: S1-B2-2                                 */
/*             Objetivo:  Bubblesort                                                */
/*                                                                                  */
/*                                    Autores:  Arthur Amaral Santos                */
/*                                                                                  */
/*                                                                                  */
/*                                                                  Data:06/05/2025 */
/*----------------------------------------------------------------------------------*/
#include <stdio.h>

void Bubblesort() {

	int numeros[5];
	int i, j, temp;

	printf("Digite 5 numeros inteiros:\n");
	for (i = 0; i < 5; i++) {
		printf("Numero %d: ", i + 1);
		scanf("%d", &numeros[i]);
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4 - i; j++) {
			if (numeros[j] > numeros[j + 1]) {
				temp = numeros[j];
				numeros[j] = numeros[j + 1];
				numeros[j + 1] = temp;
			}
		}
	}

	printf("\nNumeros em ordem crescente:\n");
	for (i = 0; i < 5; i++) {
		printf("%d ", numeros[i]);
	}
	printf("\n");
}

int main() {

	Bubblesort();
	return 0;
}
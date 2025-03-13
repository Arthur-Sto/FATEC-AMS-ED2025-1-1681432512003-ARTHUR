/*----------------------------------------------------------------------------------*/
/*   FATEC-SC#o Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: xxxxxxxxxxx                             */
/*             Objetivo: <<  colocar aqui o objetivo do programa  >>                */
/*                                                                                  */
/*                                  Autor: Arthur Amaral Santos                     */
/*                                                                   Data:10/03/2025*/
/*----------------------------------------------------------------------------------*/

#include <stdio.h>

struct Candidato {
	char Nome[50];
	float PE[4];
	float AC[5];
	float PP[10];
	float EB[3];
	float NF;
};

float MergeResults(float *Notas, int QtdNotas) {
	float NotaSomada = 0, MaiorN = Notas[0], MenorN = Notas[0];

	for (int i = 0; i < QtdNotas; i++) {
		NotaSomada += Notas[i];
		if (Notas[i] > MaiorN) MaiorN = Notas[i];
		if (Notas[i] < MenorN) MenorN = Notas[i];
	}

	return (NotaSomada - MaiorN - MenorN);
}

void Classificar(struct Candidato *Candidato, int N_Candidatos) {
	struct Candidato CandidatoC;
	int i, j;

	for (i = 0; i < N_Candidatos - 1; i++) {
		for (j = 0; j < N_Candidatos - 1 - i; j++) {
			if (Candidato[j].NF < Candidato[j + 1].NF) {
				CandidatoC = Candidato[j];
				Candidato[j] = Candidato[j + 1];
				Candidato[j + 1] = CandidatoC;
			}
		}
	}
}

int main() {
	struct Candidato Candidatos[50];
	int qtd_candidatos = 0;
	char continuar;

	printf("========= Seja bem-vindo! ========= \n\n");

	for (int i = 0; i < 50; i++) {
		printf("Insira o nome do(a) %i° candidato(a): \n", qtd_candidatos + 1);
		scanf(" %49[^\n]", Candidatos[i].Nome);

		printf("Insira as 4 notas de Provas Escritas (PE):\n");
		for (int j = 0; j < 4; j++) {
			scanf("%f", &Candidatos[i].PE[j]);
		}

		printf("Insira as 5 notas de Analises Curriculares (AC):\n");
		for (int j = 0; j < 5; j++) {
			scanf("%f", &Candidatos[i].AC[j]);
		}

		printf("Insira as 10 notas de Provas Praticas (PP):\n");
		for (int j = 0; j < 10; j++) {
			scanf("%f", &Candidatos[i].PP[j]);
		}

		printf("Insira as 3 notas de Entrevistas em Banca Avaliadora (EB):\n");
		for (int j = 0; j < 3; j++) {
			scanf("%f", &Candidatos[i].EB[j]);
		}

		float NF_PE = MergeResults(Candidatos[i].PE, 4);
		float NF_AC = MergeResults(Candidatos[i].AC, 5);
		float NF_PP = MergeResults(Candidatos[i].PP, 10);
		float NF_EB = MergeResults(Candidatos[i].EB, 3);

		Candidatos[i].NF = (NF_PE * 0.3f) + (NF_AC * 0.1f) + (NF_PP * 0.4f) + (NF_EB * 0.2f);

		qtd_candidatos++;
		
			printf("Deseja adicionar outro candidato? (S/N): ");
			scanf(" %c", &continuar);
			while(continuar != 'N' && continuar != 'S' && continuar != 'n' && continuar != 's') {
				printf("Insira uma resposta Valida.\n'S' para adicionar mais candidatos\n'N' para nao adicionar mais candidatos.\n- ");
				scanf(" %c", &continuar);
			}
			if (continuar == 'N' || continuar == 'n') {
				break;
			}
		
	}

	Classificar(Candidatos, qtd_candidatos);

	printf("\nClassificacao dos 5 melhores candidatos:\n");
	for (int i = 0; i < qtd_candidatos && i < 5; i++) {
		printf("%d°: %s - Nota Final: %.2f\n", i + 1, Candidatos[i].Nome, Candidatos[i].NF);
	}

	return 0;
}

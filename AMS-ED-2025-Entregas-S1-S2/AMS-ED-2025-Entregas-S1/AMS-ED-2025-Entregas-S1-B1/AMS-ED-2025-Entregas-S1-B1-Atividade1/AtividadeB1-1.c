#include <stdio.h>
#include <ctype.h>

float Descontar(float *Preco, char *TipoDesconto,float *Desconto) {
 
    if(*TipoDesconto == 'P'){
         
        return *Preco - (*Preco * (*Desconto/100));
    }
    else{
        return *Preco - *Desconto;
    }
}
void main()
{
	// Declarando as variaveis
	float Preco;
	float Desconto;
	char TipoDesconto;
	char porc ='%';

	// Obtendo os valores
	printf("Digite o preco original do produto: \nR$");
	while(scanf("%f", &Preco) != 1 || Preco <= 0) {               // Filtrando para
		printf("Digite um valor valido e maior que zero! \nR$");  // nao permitir negativo nem letras     
		while(getchar() != '\n');
	}

	printf("---------------------- \n Voce gostaria de aplicar um desconto a este produto? \n Em caso afirmativo, Digite 'P' para um desconto em porcentagem e 'V' para descontar um valor.\n Caso nao haja desconto, digite N.\n- ");
	scanf(" %c", &TipoDesconto);
	TipoDesconto = toupper(TipoDesconto);

	while(TipoDesconto != 'N' && TipoDesconto != 'V' && TipoDesconto != 'P') {
		printf("Insira uma resposta Valida.\n'P' para desconto em porcentagem\n'V' para desconto em valor\n'N' caso nao queira adicionar nenhum desconto.\n- ");
		scanf(" %c", &TipoDesconto);
		TipoDesconto = toupper(TipoDesconto);
	}

	if(TipoDesconto == 'P') {
		printf("Qual porcentagem de desconto deve ser aplicada?\n-");

		while(scanf("%f", &Desconto) != 1 || Desconto <= 0) {               // Filtrando para
			printf("Digite um valor valido e maior que zero! \n-");  // nao permitir negativo nem letras
			while(getchar() != '\n');
		}
		float ValorFinal = Descontar(&Preco, &TipoDesconto, &Desconto);
		printf("O Produto custava R$%.2f | Aplicou-se um desconto de %.2f%c | Com desconto, o produto custa R$%.2f", Preco, Desconto,porc, ValorFinal);
	}
	else if(TipoDesconto == 'V') {
		printf("Qual o valor do desconto que deve ser aplicado?\nR$");

		while(scanf("%f", &Desconto) != 1 || Desconto <= 0) {               // Filtrando para
			printf("Digite um valor valido e maior que zero! \nR$");  // nao permitir negativo nem letras
			while(getchar() != '\n');
		}
		float ValorFinal = Descontar(&Preco, &TipoDesconto, &Desconto);
		printf("O Produto custava R$%.2f | Aplicou-se um desconto de R$%.2f | Com desconto, o produto custa R$%.2f", Preco, Desconto, ValorFinal);
	}
	else if(TipoDesconto == 'N') {
		printf("O Produto custa R$%.2f e nenhum desconto foi aplicado.", Preco);
	}
}

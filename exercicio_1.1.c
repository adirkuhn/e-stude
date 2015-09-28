#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
	int ra;
	char nome[100];
	int idade;
	int serie;
};

void checa_idade_serie(int idade, int serie) {
	if (idade < (serie + 6)) {
		printf ("\nAluno muito jovem para essa série.\n");
	}

	if (idade > (serie + 9)) {
		printf ("\nAluno muito velho para essa série.\n");
	}
}

int main(int argc, char ** argv) {

	char continua[1] = "S";
	int qtd = 0;

	//define o tipo Aluno
	struct Aluno *aluno;

	do {
		qtd++;

		//aloca memoria para aluno
		aluno = malloc (sizeof (struct Aluno));

		//Le aluno
		printf("\nInforme o aluno:\n");
		printf("RA do aluno %d: ", qtd);
		scanf("%d", &(aluno->ra));

		printf("Nome do aluno %d: ", qtd);
		scanf("%s", aluno->nome);

		printf("Idade do aluno %d: ", qtd);
		scanf("%d", &(aluno->idade));

		printf("Série do aluno %d: ", qtd);
		scanf("%d", &(aluno->serie));

		//Imprime aluno
		printf("\n\nAluno %d: %d - %s\n", qtd, aluno->ra, aluno->nome);
		printf("Idade: %d\n", aluno->idade);
		printf("%dº Série", aluno->serie);

		checa_idade_serie(aluno->idade, aluno->serie);

		//Libera aluno da memoria
		free(aluno);

		//continua?
		printf("\n\nDeseja informar um novo aluno? (S/N) ");
		scanf("%s", continua);
	} while (strcmp(continua, "S") == 0);

	return 1;
}
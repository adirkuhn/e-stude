#include <stdio.h>

int main(int argc, char **argv) {
	//idades
	int idades[126] = {0};
	int idade = 0;

	//contadores
	int i, j;

	//Le as idades
	printf("\nInforme as idades:\n");
	while(1) {
		scanf("%d", &idade);

		if (idade < 1 || idade > 125){
			break;
		}

		idades[idade]++;
	}

	//monta historigrama
	printf("\nHistorigrama:\n");
	for (i = 0; i < ( sizeof(idades) / sizeof(idades[0]) ); i++) {
		if (idades[i] == 0) {
			continue;
		}

		printf("%03d anos: ", i);

		for (j = 0; j < idades[i]; j++) {
			printf("|");
		}

		printf("\n");
	}

	return 1;
}
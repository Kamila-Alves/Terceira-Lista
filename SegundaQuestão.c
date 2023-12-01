#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct investimento{
	int meses;
	double aporte;
	double taxa;
	double montante;
} investimento;

investimento Entrada(){
	investimento investimento;
	scanf("%d %lf %lf",&investimento.meses,&investimento.aporte,&investimento.taxa);
	return investimento;
}

void calculaMontante(investimento investimento){
	int i;
	investimento.montante = 0;
	for(i=1;i<=investimento.meses;i++){
		investimento.montante += investimento.aporte;
		investimento.montante *= 1+investimento.taxa;
		printf("Montante ao fim do mes %d: R$ %.2lf\n",i,investimento.montante);
	}
}

int main(){
	investimento investimento = Entrada();
	calculaMontante(investimento);
	return 0;
}
#include <stdio.h>
#include <math.h>

int main() {
    int meses;
    double aporte, taxa;

    printf("");
    scanf("%d", &meses);
    printf("");
    scanf("%lf", &aporte);
    printf("");                                                                                                                                                               
    scanf("%lf", &taxa);


    if (meses < 1 || meses > 240 || aporte < 1 || aporte > 5000 || taxa < 0.01 || taxa > 0.2) {
        printf("\n");
        return 1;
    }


    for (int i = 1; i <= meses; i++) {
        double montante = aporte * (1 + taxa) * ( pow(1 + taxa, i) - 1 )/taxa;
        printf("Montante ao fim do mes %d: R$ %.2lf\n", i, montante);
    }

    return 0;
}

#include <stdio.h>
#include <math.h> 

int main (){
    int meses; 
    double taxa;
    double parteM;

    printf("");
    scanf("%d", &meses); 
    printf("");
    scanf("%lf", &parteM);
    printf("");
    scanf("%lf", &taxa); 

    double montante = 0;


    for (int i = 1; i <= meses; i++) {
        montante = (montante + parteM) * (1 + taxa);
        printf("Montante ao fim do mes %d: R$ %.2f\n", i, montante);
    }
    
    return 0;

}
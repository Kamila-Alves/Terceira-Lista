#include <stdio.h>
#include <string.h>

int Valor(char romano);

void decimalPBinario(int Decimal) {
    if (Decimal > 1) {
        decimalPBinario(Decimal / 2);
 }
    printf("%d", Decimal % 2);
}

int romanoPDecimal(char numeroRomano[]) {
    int Decimal = 0;
    int i;

    for (i = 0; i < strlen(numeroRomano); i++) {
        if (i < strlen(numeroRomano) - 1 && Valor(numeroRomano[i]) < Valor(numeroRomano[i + 1])) {
            Decimal -= Valor(numeroRomano[i]);
        } else {
            Decimal += Valor(numeroRomano[i]);
        }
 }

    return Decimal;
}

int main() {
    char numeroRomano[13];
    scanf("%s", numeroRomano);

    int Decimal = romanoPDecimal(numeroRomano);

    printf("%s na base 2: ", numeroRomano);
    
    decimalPBinario(Decimal);
    if (Decimal == 0) {
        printf("0");
    }
    printf("\n");

    printf("%s na base 10: %d\n", numeroRomano, Decimal);
     printf("%s na base 16: %x\n", numeroRomano, Decimal);

    return 0;
}

int Valor(char romano) {
    switch (romano) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
 }

}
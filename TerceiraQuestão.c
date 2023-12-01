#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarFormatoPlaca(char *PlacaNumero) {
    int comprimento = strlen(PlacaNumero);
    if ((comprimento == 8 || comprimento == 7) &&
        ((isalpha(PlacaNumero[0]) && isalpha(PlacaNumero[1]) && isalpha(PlacaNumero[2]) &&
          isdigit(PlacaNumero[comprimento - 1])) ||
         (isalpha(PlacaNumero[0]) && isalpha(PlacaNumero[1]) && isalpha(PlacaNumero[2]) &&
          isalpha(PlacaNumero[3]) && isdigit(PlacaNumero[comprimento - 1])))) {
        return 1;
    }
    return 0;
}

int validarDiaSemana(char *DiaNome) {
    return (strcmp(DiaNome, "SEGUNDA-FEIRA") == 0 || strcmp(DiaNome, "TERCA-FEIRA") == 0 ||
            strcmp(DiaNome, "QUARTA-FEIRA") == 0 || strcmp(DiaNome, "QUINTA-FEIRA") == 0 ||
            strcmp(DiaNome, "SEXTA-FEIRA") == 0 || strcmp(DiaNome, "SABADO") == 0 ||
            strcmp(DiaNome, "DOMINGO") == 0);
}

int main() {
    char placaVeiculo[10], diaSemana[20];

    scanf("%s", placaVeiculo);

    for (int i = 0; i < strlen(placaVeiculo); i++) {
        placaVeiculo[i] = toupper(placaVeiculo[i]);
    }

    scanf("%s", diaSemana);

    int ultimoDigitoPlaca = placaVeiculo[strlen(placaVeiculo) - 1] - '0';

    if (!validarFormatoPlaca(placaVeiculo)) {
        printf("Placa invalida\n");
        if (!validarDiaSemana(diaSemana)) {
            printf("Dia da semana invalido\n");
        }
        return 0;
    }

    if (!validarDiaSemana(diaSemana)) {
        printf("Dia da semana invalido\n");
        return 0;
    }

    if (strcmp(diaSemana, "SABADO") == 0 || strcmp(diaSemana, "DOMINGO") == 0) {
        printf("Nao ha proibicao no fim de semana\n");
    } else {
        for (int i = 0; i < strlen(diaSemana); i++) {
            diaSemana[i] = tolower(diaSemana[i]);
        }

        if (strcmp(diaSemana, "segunda-feira") == 0 || strcmp(diaSemana, "terca-feira") == 0 ||
            strcmp(diaSemana, "quarta-feira") == 0 || strcmp(diaSemana, "quinta-feira") == 0 ||
            strcmp(diaSemana, "sexta-feira") == 0) {
            if ((ultimoDigitoPlaca == 0 || ultimoDigitoPlaca == 1) && strcmp(diaSemana, "segunda-feira") == 0) {
                printf("%s nao pode circular %s\n", placaVeiculo, diaSemana);
            } else if ((ultimoDigitoPlaca == 2 || ultimoDigitoPlaca == 3) && strcmp(diaSemana, "terca-feira") == 0) {
                printf("%s nao pode circular %s\n", placaVeiculo, diaSemana);
            } else if ((ultimoDigitoPlaca == 4 || ultimoDigitoPlaca == 5) && strcmp(diaSemana, "quarta-feira") == 0) {
                printf("%s nao pode circular %s\n", placaVeiculo, diaSemana);
            } else if ((ultimoDigitoPlaca == 6 || ultimoDigitoPlaca == 7) && strcmp(diaSemana, "quinta-feira") == 0) {
                printf("%s nao pode circular %s\n", placaVeiculo, diaSemana);
            } else if ((ultimoDigitoPlaca == 8 || ultimoDigitoPlaca == 9) && strcmp(diaSemana, "sexta-feira") == 0) {
                printf("%s nao pode circular %s\n", placaVeiculo, diaSemana);
            } else {
                printf("%s pode circular %s\n", placaVeiculo, diaSemana);
            }
        }
    }

    return 0;
}
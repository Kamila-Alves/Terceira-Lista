#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarFormatoPlaca(char *PNumero) {
    int comprimento = strlen(PNumero);
    if ((comprimento == 8 || comprimento == 7) &&
        ((isalpha(PNumero[0]) && isalpha(PNumero[1]) && isalpha(PNumero[2]) &&
          isdigit(PNumero[comprimento - 1])) ||
         (isalpha(PNumero[0]) && isalpha(PNumero[1]) && isalpha(PNumero[2]) &&
          isalpha(PNumero[3]) && isdigit(PNumero[comprimento - 1])))) {
        return 1;
    }
    return 0;
}

int validarSemana(char *Dia) {
    return (strcmp(Dia, "SEGUNDA-FEIRA") == 0 || strcmp(Dia, "TERCA-FEIRA") == 0 ||
            strcmp(Dia, "QUARTA-FEIRA") == 0 || strcmp(Dia, "QUINTA-FEIRA") == 0 ||
            strcmp(Dia, "SEXTA-FEIRA") == 0 || strcmp(Dia, "SABADO") == 0 ||
            strcmp(Dia, "DOMINGO") == 0);
}

int main() {
    char VeiculoPlaca[10], Semana[20];

    if (scanf("%9s", VeiculoPlaca) != 1) {
        printf("Erro ao ler a placa\n");
        return 1;
    }

    for (int i = 0; i < strlen(VeiculoPlaca); i++) {
        VeiculoPlaca[i] = toupper(VeiculoPlaca[i]);
    }

    if (scanf("%19s", Semana) != 1) {
        printf("Erro ao ler o dia da semana\n");
        return 1;
    }

    int ultimoDigitoPlaca = VeiculoPlaca[strlen(VeiculoPlaca) - 1] - '0';

    if (!validarFormatoPlaca(VeiculoPlaca)) {
        printf("Placa invalida\n");
        if (!validarSemana(Semana)) {
            printf("Dia da semana invalido\n");
        }
        return 0;
    }

    if (!validarSemana(Semana)) {
        printf("Dia da semana invalido\n");
        return 0;
    }

    if (strcmp(Semana, "SABADO") == 0 || strcmp(Semana, "DOMINGO") == 0) {
        printf("Nao ha proibicao no fim de semana\n");
    } else {
        for (int i = 0; i < strlen(Semana); i++) {
            Semana[i] = tolower(Semana[i]);
        }

        if (strcmp(Semana, "segunda-feira") == 0 || strcmp(Semana, "terca-feira") == 0 ||
            strcmp(Semana, "quarta-feira") == 0 || strcmp(Semana, "quinta-feira") == 0 ||
            strcmp(Semana, "sexta-feira") == 0) {
            if ((ultimoDigitoPlaca == 0 || ultimoDigitoPlaca == 1) && strcmp(Semana, "segunda-feira") == 0) {
                printf("%s nao pode circular %s\n", VeiculoPlaca, Semana);
            } else if ((ultimoDigitoPlaca == 2 || ultimoDigitoPlaca == 3) && strcmp(Semana, "terca-feira") == 0) {
                printf("%s nao pode circular %s\n", VeiculoPlaca, Semana);
            } else if ((ultimoDigitoPlaca == 4 || ultimoDigitoPlaca == 5) && strcmp(Semana, "quarta-feira") == 0) {
                printf("%s nao pode circular %s\n", VeiculoPlaca, Semana);
            } else if ((ultimoDigitoPlaca == 6 || ultimoDigitoPlaca == 7) && strcmp(Semana, "quinta-feira") == 0) {
                printf("%s nao pode circular %s\n", VeiculoPlaca, Semana);
            } else if ((ultimoDigitoPlaca == 8 || ultimoDigitoPlaca == 9) && strcmp(Semana, "sexta-feira") == 0) {
                printf("%s nao pode circular %s\n", VeiculoPlaca, Semana);
            } else {
                printf("%s pode circular %s\n", VeiculoPlaca, Semana);
            }
        }
    }

    return 0;
}

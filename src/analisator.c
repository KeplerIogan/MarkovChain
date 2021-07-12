#include "analisator.h"

int analisys(FILE *readFile) {

    int lenght = 0;
    char symbol = getc(readFile);

    while (symbol != EOF) {


        lenght++;
        printf("%c", symbol);
        symbol = getc(readFile);
    }

    printf("\n\n");

    int chain[lenght];

    fseek(readFile, 0, SEEK_SET);

    for (int i = 0; i < lenght; i++) {

        chain[i] = getc(readFile) - '0';
    }

    float matrix[2][2];

    matrix[0][0] = 0;
    matrix[0][1] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = 0;

    for (int i = 0; i < lenght - 1; i++) {

        matrix[chain[i]][chain[i + 1]] += 1;
    }


    float del = matrix[0][0] + matrix[0][1];
    matrix[0][0] = matrix[0][0] / (del);
    matrix[0][1] = matrix[0][1] / (del);

    del = matrix[1][0] + matrix[1][1];
    matrix[1][0] = matrix[1][0] / (del);
    matrix[1][1] = matrix[1][1] / (del);

    printf("Matrix for this Markow chain:\n\n");

    printf("%.3f %.3f\n", matrix[0][0], matrix[0][1]);
    printf("%.3f %.3f\n\n", matrix[1][0], matrix[1][1]);



    printf("Complete!\n\n");

    return 0;
}

#include "generator.h"

int generation() {

    srand(time(NULL));

    float state[2][2];

    state[0][0] = 0;
    state[0][1] = 0;
    state[1][0] = 0;
    state[1][1] = 0;

    int right = 0, lenght = 0;

    while (right != 1) {
        printf("Enter the matrix(2 numbers separated by [space]):\n\n");

        scanf("%f%f", &state[0][0], &state[0][1]);
        scanf("%f%f", &state[1][0], &state[1][1]);

        if (((state[0][0] + state[0][1]) > 1) || ((state[1][0] + state[1][1]) > 1)) {

            printf("ERROR!!! One of the sums of probabilites > 1\n\n");

        } else { right++; }
    }

    printf("\nEnter lenght of chain: ");
    scanf("%d", &lenght);

    int chain[lenght];
    int counter = lenght, flag_sost = 0;
    float ran;

    while (counter != 0) {

        ran = rand() % 100;
        ran = ran / 100;

        if (flag_sost == 0) {
            if(ran <= state[0][0]) {

                chain[lenght - counter] = flag_sost;
                counter--;
            } else {

                flag_sost++;
                chain[lenght - counter] = flag_sost;
                counter--;
            }
        } else {

            if(ran <= state[1][0]) {

                chain[lenght - counter] = flag_sost;
                counter--;
            } else {

                flag_sost--;
                chain[lenght - counter] = flag_sost;
                counter--;
            }
        }
    }

    printf("\n\nChain: \n\n");

    for (int i = 0; i < lenght; i++) {

        printf("%d", chain[i]);
    }

    char answer[80];
    char symbol;



    printf("\nPrint file name for save the results(80 max symbols): ");
    scanf("%s", answer);

    FILE *fileResult = fopen(answer, "w");
    if (fileResult == NULL) {

        printf("\nERROR!!! File can't be save.\n\n");
        return 0;

    }

    for (int i = 0; i < lenght; i++) {
        symbol = chain[i] + '0';
        fprintf(fileResult, "%c", symbol);
    }

    fclose(fileResult);

    printf("\nComplete!\n\n");

    return 0;

}

#include "generator.h"
#include "analisator.h"

int main(int argc, char* argv[]) {

    char name_of_file[80];
    int flag = 0;


    printf("\n\nWhat will you do?\n\n");
    printf("1.Generation of the Markov chain\n");
    printf("2.Markov chain analisys\n\n");

    scanf("%d", &flag);

    if (flag == 1) {

        generation();

    } else {


        printf("Please, print the name of file whit chain(80 max symbol): ");
        scanf("%s", name_of_file);

        FILE *readFile = fopen(name_of_file, "r");

        analisys(readFile);

        fclose(readFile);
    }

    return 0;
}

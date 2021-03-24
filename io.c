#include "io.h"


void lerItensParaArray(FILE *entrada, int *array)
{
    int i = 0;
    while (!feof(entrada))
    {
        fscanf(entrada, "%d\n", &array[i]);
        i++;
    }
}

void imprimeArquivoSaida(FILE *saida, int *array, int N)
{
    for (int i = 0; i < N; i++)

        fprintf(saida, "%d\n", array[i]);
}
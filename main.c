#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_malloc.h"

int main(int argc, char *argv[])
{
    char *vetor;
    int i;

    MyMallocInit(TAMANHO_MAX_MALLOC);

    vetor = MyMalloc(10);
    if (vetor == NULL)
    {
        fprintf(stderr, "chamada MyMalloc() falhou\n");
        fflush(stderr);
        exit(1);
    }

    for (i = 0; i < 9; i++)
    {
        vetor[i] = 'a' + i;
    }
    vetor[9] = 0;

    printf("Nova string: %s\n", vetor);

    MyMallocFree(vetor);

    return (0);
}
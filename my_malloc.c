#include "my_malloc.h"

static struct malloc_struct *ListaLivre;
static unsigned char Buff[TAMANHO_MAX_MALLOC];

struct malloc_struct
{
    struct malloc_struct *proximo;
    struct malloc_struct *anterior;
    int tamanho;
    unsigned char *buffer;
};

MyMallocInit(int tamanho)
{
    ListaLivre = (struct malloc_struct *)Buff;
    ListaLivre->anterior = NULL;
    ListaLivre->proximo = NULL;
    ListaLivre->tamanho = sizeof(Buff) - sizeof(struct malloc_struct);
    ListaLivre->buffer = (unsigned char *)(Buff + sizeof(struct malloc_struct));

    return 1;
}
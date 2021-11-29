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

InitMyMalloc()
{

    ListaLivre = (struct malloc_struct *)Buff;
    ListaLivre->proximo = NULL;
    ListaLivre->anterior = NULL;
    ListaLivre->tamanho = sizeof(Buff) - sizeof(struct malloc_struct);
    ListaLivre->buffer = (unsigned char *)(Buff + sizeof(struct malloc_struct));
}
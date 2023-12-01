#include "my_malloc.h"

int MyMallocInit()
{
    ListaLivre->tamanho = sizeof(Buff) - sizeof(struct bloco_struct);
    ListaLivre->proximo = NULL;
    ListaLivre->livre = true;
    return 1;
}

void *MyMalloc(size_t numBytes)
{
    struct bloco_struct *atual, *anterior;
    void *resultado;

    if (!(ListaLivre->tamanho))
    {
        MyMallocInit();
        printf("MyMemória iniciada\n\n");
    }

    atual = ListaLivre;

    while (((atual->tamanho) < numBytes) || (((atual->tamanho) == 0) && (atual->proximo != NULL)))
    {
        anterior = atual;
        atual = atual->proximo;
    }
    if ((atual->tamanho) == numBytes)
    {
        atual->livre = false;
        resultado = (void *)(++atual);
        return resultado;
    }
    else if ((atual->tamanho) > (numBytes + sizeof(struct bloco_struct)))
    {
        MyMallocSplit(atual, numBytes);
        resultado = (void *)(++atual);
        return resultado;
    }
    else
    {
        resultado = NULL;
        printf("Memória insuficiente\n\n");
        return resultado;
    }
}

void MyMallocSplit(struct bloco_struct *espaco, size_t tamanho)
{
    struct bloco_struct *novo = (void *)(void *)espaco + tamanho + sizeof(struct bloco_struct);
    novo->tamanho = (espaco->tamanho) - tamanho - sizeof(struct bloco_struct);
    novo->livre = true;
    novo->proximo = espaco->proximo;
    espaco->tamanho = tamanho;
    espaco->livre = false;
    espaco->proximo = novo;
}

void MyMallocMerge()
{
    struct bloco_struct *atual, *anterior;
    atual = ListaLivre;
    while ((atual->proximo) != NULL)
    {
        if ((atual->livre) && (atual->proximo->livre))
        {
            atual->tamanho += (atual->proximo->tamanho) + sizeof(struct bloco_struct);
            atual->proximo = atual->proximo->proximo;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void MyMallocFree(void *ptr)
{
    if (((void *)Buff <= ptr) && (ptr <= ((void *)(Buff + TAMANHO_MAX_MALLOC))))
    {
        struct bloco_struct *atual = ptr;
        --atual;
        atual->livre = true;
        MyMallocMerge();
        printf("MyMallocFree():\nBloco %p liberado\n\n", atual);
    }
    else
        printf("MyMallocFree():\nPonteiro inválido\n\n");
}

void MyMallocGerency(void *ptr)
{
    struct bloco_struct *bloco = ptr;
    --bloco;
    printf("MyMallocGerency():\nBloco: %p \nEspaço alocado: %ld bytes\n\n", bloco, bloco->tamanho);
}

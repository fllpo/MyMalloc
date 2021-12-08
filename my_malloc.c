#include "my_malloc.h"

int MyMallocInit()
{
    ListaLivre = (struct bloco_struct *)Buff;
    ListaLivre->tamanho = sizeof(Buff) - sizeof(struct bloco_struct);
    ListaLivre->proximo = NULL;
    ListaLivre->livre=true;
    return 1;
}

void *MyMalloc(size_t numBytes)
{
    struct bloco_struct *atual, *anterior;
    void *resultado;

    if (!(ListaLivre->tamanho))
    {
        MyMallocInit();
        printf("Memoria iniciada\n");
    }
    
    atual=ListaLivre;

    while (((atual->tamanho)<numBytes)||(((atual->tamanho)==0)&&(atual->proximo!=NULL)))
    {
        anterior=atual;
        atual=atual->proximo;
        printf("Bloco verificado\n");
    }
    if ((atual->tamanho)==numBytes)
    {
        atual->livre=false;
        resultado=(void*)(++atual);
        printf("%ld bytes alocado\n", (int*)numBytes);
        return resultado;
    }
    else if ((atual->tamanho)>(numBytes+sizeof(struct bloco_struct))){
        MyMallocSplit(atual,numBytes);
        resultado=(void*)(++atual);
        printf("%ld bytes alocado com divisão\n", (int*)numBytes);
        return resultado;
    }
    else
    {
        resultado=NULL;
        printf("Memoria insuficiente\n");
        return resultado;
    }
}

void MyMallocSplit(struct bloco_struct *espaco, size_t tamanho){

    struct bloco_struct *novo=(void*)(void*)espaco+tamanho+sizeof(struct bloco_struct);
    novo->tamanho=(espaco->tamanho)-tamanho-sizeof(struct bloco_struct);
    novo->livre=true;
    novo->proximo=espaco->proximo;
    espaco->tamanho=tamanho;
    espaco->livre=false;
    espaco->proximo=novo;
}

void MyMallocMerge(){
    struct bloco_struct *atual, *anterior;
    atual=ListaLivre;
    while ((atual->proximo)!=NULL)
    {
        if ((atual->livre)&&(atual->proximo->livre))
        {
            atual->tamanho+=(atual->proximo->tamanho)+sizeof(struct bloco_struct);
            atual->proximo=atual->proximo->proximo;
        }
        anterior=atual;
        atual=atual->proximo;
    }
}

int MyMallocFree(void *ptr)
{
    if(((void*)Buff<=ptr)&&(ptr<=(void*)(Buff+TAMANHO_MAX_MALLOC))){
        struct bloco_struct *atual=ptr;
        --atual;
        atual->livre=true;
        MyMallocMerge();
        printf("Bloco liberado\n");
        return 1;
    }
    else {
        printf("Ponteiro inválido\n");
        return 0;
    }
}
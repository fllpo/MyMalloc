#if !defined(MY_MALLOC_H)
#define MY_MALLOC_H

#define TAMANHO_MAX_MALLOC (1024 * 1024 * 16)

int MyMallocInit(int tamanho);
void *MyMalloc(int tamanho);
int MyMallocFree(void *buffer);
void MyMallocGerency();

#endif

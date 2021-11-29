#if !defined(MY_MALLOC_H)
#define MY_MALLOC_H

#define TAMANHO_MAX_MALLOC (1024 * 1024 * 16)

void InitMyMalloc();
void *MyMalloc(int tamanho);
void MyFree(void *buffer);

void PrintMyMallocFreeList();

#endif

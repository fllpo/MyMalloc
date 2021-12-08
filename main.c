#include "my_malloc.h"

int main(int argc, char *argv[])
{
    int *p = (int)MyMalloc(100*sizeof(int));
    MyMallocFree(p);
    
    return 0;
}

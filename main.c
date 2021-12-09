#include "my_malloc.h"

int main(int argc, char *argv[])
{
    int *p = (int*)MyMalloc(250*sizeof(int));
    int *r = (int*)MyMalloc(1000*sizeof(int));

    MyMallocFree(p);
    MyMallocFree(r);

        return 0;
}

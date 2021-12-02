#include "my_malloc.h"

int main(int argc, char *argv[])
{
    
    int *p = MyMalloc(400*sizeof(int));
    int *q = MyMalloc(400*sizeof(int));

    return 0;
}
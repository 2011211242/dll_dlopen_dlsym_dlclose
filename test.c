#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "types.h"

#define LIB_CACULATE_PATH "./libcaculate.so"

typedef int32 (*CAC_FUNC)(int, int);

int32 main()
{
    void *handle;
    uint8 *error;
    CAC_FUNC cac_func = NULL;

    /* open ddl */
    handle = dlopen(LIB_CACULATE_PATH, RTLD_LAZY);
    
    if (NULL == handle) 
    {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();

    /* get function add sub mul div */

    cac_func = (CAC_FUNC)dlsym(handle, "add");
    printf("add: %d\n", (*cac_func)(2,7));

    cac_func = (CAC_FUNC)dlsym(handle, "sub");
    printf("sub: %d\n", cac_func(9,2));

    cac_func = (CAC_FUNC)dlsym(handle, "mul");
    printf("mul: %d\n", cac_func(3,2));

    cac_func = (CAC_FUNC)dlsym(handle, "div");
    printf("div: %d\n", cac_func(8,2));

    /* close ddl */

    /*
    dlclose(handle);
    handle = dlopen("/lib/x86_64-linux-gnu/libc.so.6", RTLD_LAZY);
    *
    if (NULL == handle)
    {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);

    }
    dlerror();
    */
    /*
    void* (*malloc_func)(size_t) = (void*(*)(size_t)) dlsym(handle, "malloc");
    int * ptr = NULL;
    ptr = malloc_func(sizeof(int));
    *ptr = 4;
    printf("%x\n", *ptr); 
    */
    malloc(sizeof(int));
    exit(EXIT_SUCCESS);
}


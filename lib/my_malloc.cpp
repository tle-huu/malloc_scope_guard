#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include "malloc_scope_guard.hpp"

#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

using MALLOC_TYPE = void* (*)(size_t); 

void* malloc(size_t size)
{
    static void* (*real_malloc)(size_t) = NULL;
    if (!real_malloc)
        real_malloc =(MALLOC_TYPE) dlsym(RTLD_NEXT, "malloc");

    void *p = real_malloc(size);
//  fprintf(stderr, "[%s:%lu] malloc(%lu) = %p\n", file, line, size, p);
    if (MallocScopeGuard::in_scope)
    {
        fprintf(stderr, "[%s:%lu] Forbidden use of malloc(%lu) = %p\n", MallocScopeGuard::file, MallocScopeGuard::line, size, p);
        abort();
    }


    return p;
}


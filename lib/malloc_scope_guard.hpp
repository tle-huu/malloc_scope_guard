#pragma once

#include <cstdlib>

#ifdef DEBUG
#define MALLOC_SCOPE_GUARD \
        MallocScopeGuard guard(__LINE__, __FILE__);
#else
#define MALLOC_SCOPE_GUARD ""
#endif

class MallocScopeGuard
{

public:
    static thread_local unsigned char in_scope;
    static thread_local  size_t line;
    static thread_local  const char *file;

public:
    MallocScopeGuard(size_t current_line, const char * current_file);

    ~MallocScopeGuard();

private:
    size_t old_line_;
    const char * old_file_;
    unsigned char old_in_scope_;

};

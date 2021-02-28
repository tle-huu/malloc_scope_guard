#include "malloc_scope_guard.hpp"

#include <cstdio>

thread_local unsigned char MallocScopeGuard::in_scope = 0;
thread_local  size_t MallocScopeGuard::line = 0;
thread_local  const char *MallocScopeGuard::file = nullptr;

MallocScopeGuard::MallocScopeGuard(size_t current_line, const char * current_file)
{

// Uncomment to disable nested scope guard
/*
    if (in_scope)
    {
        fprintf(stderr, "[%s:%lu] MallocScopeGuard is already in scope (double scope).\n", current_file, current_line);
        abort();
    }
*/

    old_line_ = line;
    old_file_ = file;
    old_in_scope_ = in_scope;

    in_scope = 1;
    line = current_line;
    file = current_file;
}

MallocScopeGuard::~MallocScopeGuard()
{
    line = old_line_;
    file = old_file_;
    in_scope = old_in_scope_;
}


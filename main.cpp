#include "malloc_scope_guard.hpp"

#include <stdio.h>
#include <vector>
#include <thread>


void foo()
{
    std::vector<int> test;
    int i = 1;
    malloc(400);
    while (i++ < 100000)
    {
        malloc(1);
        if (i % 1000 == 0)
        {
            MALLOC_SCOPE_GUARD;
            printf("foo %d\n", i);
            test.push_back(i);
        }
    }

}

void bar()
{
    int i = 1;
    MALLOC_SCOPE_GUARD;
    while (i++ < 100000)
    {
        if (i % 1000 == 0)
        {
            printf("bar %d\n", i);
        }
    }



}



int main()
{
    printf("Go\n");


    printf("\n======= Double scopes test =====\n");
    {
        printf("First scope\n");
        MALLOC_SCOPE_GUARD;
        {
            printf("second scope\n");
            MALLOC_SCOPE_GUARD;
        }
    }

    printf("\n======= Thread tests =====\n");
    std::thread first(foo);
    std::thread second(bar);


    first.join();
    second.join();
    return 0;
}

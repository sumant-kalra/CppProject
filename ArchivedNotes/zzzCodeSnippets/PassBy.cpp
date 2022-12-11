// What will be the output of the program below?

#if 1
#include <iostream>

void function(int* ptr) // 2.1
{
    ptr = new int(10); // 2.2
} // 2.3

int main()
{
    int* p = nullptr; // 1
    function(p); // 2
    std::cout<<*p<<std::endl; // 3s
    delete p; // 4

    return 0;
}
#endif

/*
It will be segmentation fault or memory access voilation.
Let us understand the problem step by step.
1. A pointer is created and is initialized to nullptr.
2. The pointer is passed to the function, lets check how the function takes this variable;
    2.1 function takes the pointer by value, which means that the value (nullptr) of the
        the original pointer passed is copied, and it is used to initialize the pointer ptr
        in the argument of the function.
    2.2 The newly created pointer is assigned an integer value of 10.
    2.3 The function scope ends, and the ptr created on stack is deleted,
        since the pointer ptr is not related to the pointer p in the main function,
        the changes made by the function will not be reflected in the main.
3. The pointer p is dereferenced which means, printing the value of the variable it is
   pointing to. Since the pointer p is not pointing to any variable. Dereferencing p
   the segmentation fault run-time error.
*/

// Ways to fix it.
// That is the assignment of the int(10) should be done to the original
// pointer p in the main.

// 1. Pass by value
#if 0

#include <iostream>

void function(int** ptr) // 2.1 Take in the address of p from the main
{
    *ptr = new int(10); // 2.2
} // 2.3

int main()
{
    int* p = nullptr; // 1
    function(&p); // 2 Pass the address of the pointer
    std::cout<<*p<<std::endl; // 3
    delete p; // 4

    return 0;
}
#endif

// 2. Pass by reference
#if 0

#include <iostream>

void function(int* & ptr) // 2.1 Create a reference of p from the main
{
    ptr = new int(10); // 2.2
} // 2.3

int main()
{
    int* p = nullptr; // 1
    function(p); // 2 Pass the pointer
    std::cout<<*p<<std::endl; // 3
    delete p; // 4

    return 0;
}
#endif

// 3. Return a pointer from the function
#if 0
#include <iostream>

int* function(int* ptr) // 2.1
{
    ptr = new int(10); // 2.2
    return ptr;
} // 2.3

int main()
{
    int* p = nullptr; // 1
    p = function(p); // 2
    std::cout<<*p<<std::endl; // 3
    delete p; // 4

    return 0;
}
#endif

// 4. Return a reference from the function - Wont work
#if 0
#include <iostream>

int*& function(int* ptr) // 2.1
{
    ptr = new int(10); // 2.2
    return ptr;
    // returning a reference of a stack variable which will lead
    // to an error as the variable dies as the function finishes
    // it's execution.
    // We actually wanted to return the address of the variable
    // pointed by the ptr. See the option 3.
} // 2.3

int main()
{
    int* p = nullptr; // 1
    int*& ptr = function(p); // 2
    std::cout<<*ptr<<std::endl; // 3
    delete p; // 4

    return 0;
}
#endif

#define MAIN 1
#define MEMORY_TRACKING 1

#include <iostream>

#if MEMORY_TRACKING

static int heapAllocationsCount = 0;
void *operator new(size_t sizeInBytes)
{
    std::cout << ++heapAllocationsCount << "\n";
    return malloc(sizeInBytes);
}

void operator delete(void *ptr)
{
    std::cout << --heapAllocationsCount << "\n";
    free(ptr);
}

#endif

#if MAIN
int main(int argc, char const *argv[])
{
    int *ptr = new int[10];
    std::cout << ptr << "\n";
    delete[] ptr;
}
#endif
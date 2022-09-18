#define MAIN 1
#define TRACK_MEMORY 1

#include <iostream>

#if TRACK_MEMORY
static int s_heapAllocationCount = 0;

void *operator new(size_t sizeBytes)
{
    std::cout << ++s_heapAllocationCount << "\n";
    return malloc(sizeBytes);
}
#endif

#if MAIN
#include <string>
#include <string_view>

void print(const std::string_view &message)
{
    std::cout << message << "\n";
}

int main(int argc, char *argv[])
{
    std::string name = "Sumant Kalra, Physicist. The goal is to be a Physicist like Richard P Feynman";
    std::string_view firstName(name.c_str(), 24);
    std::string_view lastName(name.c_str());

    print(firstName);
    print(lastName);

    return 0;
}
#endif
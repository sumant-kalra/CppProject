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

void print(const std::string &message)
{
    std::cout << message << "\n";
}

int main(int argc, char *argv[])
{
    std::string name = "Sumant Kalra, Physicist. The goal is to be a Physicist like Richard P Feynman";
    std::string firstName = name.substr(0, 24);
    std::string lastName = name.substr(25, std::string::npos);

    print(firstName);
    print(lastName);

    return 0;
}
#endif
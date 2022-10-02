#define MEMORY_TRACE 1

#include <iostream>

#if MEMORY_TRACE
#include "MemoryTrace.h"

void *operator new(size_t nBytes)
{
  memory_trace::MemoryTraceHeap::addHeapAllocation(nBytes);
  size_t totalBytesToBeAllocated = nBytes + sizeof(size_t);
  void *p = malloc(totalBytesToBeAllocated);
  size_t *ptr = (size_t *)p;
  ptr[0] = nBytes;
  return (void *)&ptr[1];
}

void operator delete(void *ptr)
{
  size_t *p = (size_t *)ptr;
  size_t nBytes = p[-1];
  memory_trace::MemoryTraceHeap::subractHeapAllocation(nBytes);
  free((void *)(p - 1));
}

#endif

int main(int argc, char *argv[])
{
  //std::cout << "Hello World!\n";

  std::string name = "Sumant Kalra is stupid again. I hope it stays our secret.\n";
  std::cout << name << "\n";

  memory_trace::MemoryTraceHeap::printMemoryMetrics();

  return 0;
}

#include <iostream>

#include "MemoryTrace.h"

// ----------------------------------------------------------------------------------------------------------------------- //

int memory_trace::MemoryTraceHeap::s_totalHeapAllocation = 0;
int memory_trace::MemoryTraceHeap::s_totalHeapDeallocation = 0;

// ----------------------------------------------------------------------------------------------------------------------- //

void memory_trace::MemoryTraceHeap::addHeapAllocation(int memoryBytes)
{
    s_totalHeapAllocation += memoryBytes;
    std::cout << "[MEMORY] Memory allocated on heap! Bytes allocated: " << memoryBytes << "\n";
    printMemoryMetrics();
}

// ----------------------------------------------------------------------------------------------------------------------- //

void memory_trace::MemoryTraceHeap::subractHeapAllocation(int memoryBytes)
{
    s_totalHeapDeallocation -= memoryBytes;
    std::cout << "[MEMORY] Memory deallocated from heap! Bytes deallocated: " << memoryBytes << "\n";
    printMemoryMetrics();
}

// ----------------------------------------------------------------------------------------------------------------------- //

void memory_trace::MemoryTraceHeap::printMemoryMetrics()
{
    std::cout << "\n##### Heap Memory Metrics #####\n";
    std::cout << "## Total Heap Memory Allocations: " << s_totalHeapAllocation << " bytes\n";
    std::cout << "## Total Heap Memory Deallocations: " << s_totalHeapDeallocation << " bytes\n";
    std::cout << "## Heap Memory in use: " << s_totalHeapAllocation - s_totalHeapDeallocation << " bytes\n";
}

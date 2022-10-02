#include <iostream>
#include <thread>
#include <mutex>

#include "MemoryTrace.h"

std::mutex mu1;
std::mutex mu2;

// ----------------------------------------------------------------------------------------------------------------------- //

int memory_trace::MemoryTraceHeap::s_totalHeapAllocation = 0;
int memory_trace::MemoryTraceHeap::s_totalHeapDeallocation = 0;

// ----------------------------------------------------------------------------------------------------------------------- //

void memory_trace::MemoryTraceHeap::addHeapAllocation(int memoryBytes)
{
    std::lock_guard<std::mutex> lock(mu1);
    s_totalHeapAllocation += memoryBytes;
    std::cout << "\n[MEMORY] From thread id: " << std::this_thread::get_id() << "\n";
    std::cout << "[MEMORY] Memory allocated on heap! Bytes allocated: " << memoryBytes << "\n\n";
}

// ----------------------------------------------------------------------------------------------------------------------- //

void memory_trace::MemoryTraceHeap::subractHeapAllocation(int memoryBytes)
{
    std::lock_guard<std::mutex> lock(mu2);
    s_totalHeapDeallocation += memoryBytes;
    std::cout << "\n[MEMORY] From thread id: " << std::this_thread::get_id() << "\n";
    std::cout << "[MEMORY] Memory deallocated from heap! Bytes deallocated: " << memoryBytes << "\n\n";
}

// ----------------------------------------------------------------------------------------------------------------------- //

void memory_trace::MemoryTraceHeap::printMemoryMetrics()
{
    std::cout << "\n[MEMORY] From thread id: " << std::this_thread::get_id() << "\n";
    std::cout << "##### Heap Memory Metrics #####\n";
    std::cout << "## Total Heap Memory Allocations: " << s_totalHeapAllocation << " bytes\n";
    std::cout << "## Total Heap Memory Deallocations: " << s_totalHeapDeallocation << " bytes\n";
    std::cout << "## Heap Memory in use: " << s_totalHeapAllocation - s_totalHeapDeallocation << " bytes\n\n";
}

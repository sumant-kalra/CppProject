#ifndef MEMORY_TRACE_H
#define MEMORY_TRACE_H

namespace memory_trace
{
    class MemoryTraceHeap
    {
    private:
        static int s_totalHeapAllocation;
        static int s_totalHeapDeallocation;

    public:
        MemoryTraceHeap() = delete;
        MemoryTraceHeap(const MemoryTraceHeap &) = delete;
        MemoryTraceHeap &operator=(const MemoryTraceHeap &) = delete;

        static void addHeapAllocation(int memoryBytes);
        static void subractHeapAllocation(int memoryBytes);

        static void printMemoryMetrics();
    };

}

#endif

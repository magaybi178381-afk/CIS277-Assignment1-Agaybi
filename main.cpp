#include "MemoryPool.h"

int main()
{
    MemoryPool pool(512, 8);

    std::cout << "Block Size: "
              << pool.blockSize()
              << " bytes\n";

    std::cout << "Blocks: "
              << pool.capacity() / pool.blockSize()
              << "\n";

    std::cout << "Capacity: "
              << pool.capacity()
              << " bytes\n\n";


    void* packet1 = pool.allocate();
    void* packet2 = pool.allocate();
    void* packet3 = pool.allocate();

    std::cout << "Packet 1: " << packet1 << "\n";
    std::cout << "Packet 2: " << packet2 << "\n";
    std::cout << "Packet 3: " << packet3 << "\n\n";

    std::cout << "Available blocks: "
              << pool.availableBlocks()
              << "\n";

    std::cout << "Allocated blocks: "
              << pool.allocatedBlocks()
              << "\n\n";


    unsigned char packet[] =
    {
        0x45, 0x00, 0x00, 0x3C,
        0xAB, 0xCD, 0x12, 0x34
    };

    std::memcpy(packet1, packet, sizeof(packet));

    std::cout << "Binary packet written to Packet 1.\n";

    unsigned char* data =
        static_cast<unsigned char*>(packet1);

    std::cout << "Binary data: ";

    for (size_t i = 0; i < sizeof(packet); i++)
    {
        std::cout << std::hex
                  << static_cast<int>(data[i])
                  << " ";
    }

    std::cout << std::dec << "\n\n";


    pool.deallocate(packet2);

    std::cout << "Packet 2 released.\n";

    std::cout << "Available blocks: "
              << pool.availableBlocks()
              << "\n";

    std::cout << "Allocated blocks: "
              << pool.allocatedBlocks()
              << "\n\n";


    void* packet4 = pool.allocate();

    std::cout << "Packet 4: "
              << packet4
              << "\n";

    if (packet4 == packet2)
    {
        std::cout << "Packet 4 reused Packet 2.\n";
    }

    std::cout << "\n";


    while (pool.allocate() != nullptr)
    {
    }

    std::cout << "Available blocks: "
              << pool.availableBlocks()
              << "\n";

    std::cout << "Allocated blocks: "
              << pool.allocatedBlocks()
              << "\n";


    void* failed = pool.allocate();

    if (failed == nullptr)
    {
        std::cout << "allocate() returned nullptr.\n";
    }

    std::cout << "\n";


    pool.deallocate(packet1);

    if (!pool.deallocate(packet1))
    {
        std::cout << "Double deallocation rejected.\n";
    }

    return 0;
}

#include <iostream>

#include "chain.hpp"

int main(int argc, char const *argv[])
{
    Chain blockChain = Chain();

    std::cout << "Mining block 1 . . . " << std::endl;
    blockChain.addBlock(Block(1, "Block 1 Data"));

    std::cout << "Mining block 2 . . . " << std::endl;
    blockChain.addBlock(Block(2, "Block 2 Data"));

    std::cout << "Mining block 3 . . . " << std::endl;
    blockChain.addBlock(Block(3, "Block 3 Data"));
    
    return 0;
}

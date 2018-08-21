#ifndef CHAIN_HPP
#define CHAIN_HPP

#include <cstdint>
#include <vector>

#include "block.hpp"

class Chain 
{
    private: 
        uint32_t _difficulty;
        std::vector<Block> _chainDS;
        Block _getLastBlock() const;

    public:
        // Default constructor
        Chain();

        // To add a new block to the chain
        void addBlock(Block newBlock);
};

#endif
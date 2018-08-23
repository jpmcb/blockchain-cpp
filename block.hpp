#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <cstdint>
#include <iostream>
#include <string>

class Block 
{
    private: 
        uint32_t _index;
        int64_t _nonce;
        std::string _data;
        std::string _hash;
        time_t _time;

        std::string _calculateHash() const;

    public:
        // Default block constructor
        Block();

        // Constructor to set index and data
        Block(uint32_t inIndex, const std::string &inData);

        // the previous hash string
        std::string prevHash;

        // 
        std::string getHash();

        void mineBlock(uint32_t difficulty);
};

#endif

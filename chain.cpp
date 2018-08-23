#include "chain.hpp"

/*****************
 * Default constructor
 * **************/
Chain::Chain()
{
    this-> _chainDS.push_back(Block(0, "Genesis Block"));
    _difficulty = 6;
}

/***************
 * Adding block implementation
 * ************/
void Chain::addBlock(Block newBlock)
{
    newBlock.prevHash = _getLastBlock().getHash();
    newBlock.mineBlock(this-> _difficulty);
    _chainDS.push_back(newBlock);
}

/**************
 * Get the last block in the chain
 * *************/
Block Chain::_getLastBlock() const
{
    return _chainDS.back();
}
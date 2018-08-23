#include <sstream>

#include "block.hpp"
#include "sha256.hpp"

/*************
 * Default block constructor
 * ************/

Block::Block()
{
    this-> _index = -1;
    this-> _data = "INVALID";
    this-> _nonce = -1;
    this-> _time = time(NULL);
}


/**************
 * Overloaded block constructor
 * ************/

Block::Block(uint32_t inIndex, const std::string &inData)
{
    this-> _index = inIndex;
    this-> _data = inData;
    this-> _nonce = -1;
    this-> _time = time(NULL);
}


/***************
 * Returns the private hash data member
 * ************/

std::string Block::getHash()
{
    return _hash;
}


/****************
 * implementation to mine the block, creating the hash
 * *************/

void Block::mineBlock(uint32_t difficulty)
{
    char* charArr = new char[difficulty + 1];
    std::memset(charArr, '0', sizeof(char) * difficulty);

    charArr[difficulty] = '\0';

    std::string buildString(charArr);

    std::cout << "The buildString: " << buildString << std::endl;

    do 
    {
        this-> _nonce++;
        this-> _hash = _calculateHash();
        // std::cout << _hash << std::endl;
    } while (this-> _hash.substr(0, difficulty) != buildString);

    std::cout << "Block Mined: " << this-> _hash << std::endl;
}


/*************
 * Calculates the hash using the sha256 library hashing method
 * ************/

std::string Block::_calculateHash() const
{
    std::stringstream ss;
    ss << this-> _index << this-> _time << this-> _data << this-> _nonce << this-> prevHash;

    return sha256(ss.str());
}
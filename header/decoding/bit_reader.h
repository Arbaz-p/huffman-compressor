#ifndef BIT_READER_H
#define BIT_READER_H
#include<vector>
#include<stdint.h>
#include<fstream>
#include "huffman_tree.h"
class BitReader{
    std::vector<char> buffer;
    size_t byteIndex;
    int bitIndex;
    uint8_t getNextBit();
    public:
    BitReader(const std::vector<char> &buf,size_t i);
    void extract_bits(std::ofstream &out,const std::shared_ptr<huffman_node> &root,int pad);
};

#endif
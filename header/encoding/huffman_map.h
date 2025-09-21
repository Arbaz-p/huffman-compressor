#ifndef HUFFMAN_MAP_H
#define HUFFMAN_MAP_H
#include "huffman_tree.h"
#include<unordered_map>
#include<stdint.h>
class Huffman_Map{
    public:
    void construct_huffman_map(const std::shared_ptr<huffman_node> &node,std::unordered_map<char,std::pair<uint16_t,uint8_t>> &map,uint16_t number,uint8_t len);
};
#endif
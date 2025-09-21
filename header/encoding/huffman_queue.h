#include "huffman_tree.h"
#ifndef HUFFMAN_QUEUE_H
#define HUFFMAN_QUEUE_H
#include<queue>
#include<stdint.h>
#include<iostream>
struct huffman_node;
struct Compare{
    bool operator()(const std::shared_ptr<huffman_node> &a,std::shared_ptr<huffman_node> &b);
};
class Huffman_Queue{
    public:
    std::priority_queue<std::shared_ptr<huffman_node>,std::vector<std::shared_ptr<huffman_node>>,Compare> construct_huffman_queue(uint32_t freq_table[]);
};
#endif
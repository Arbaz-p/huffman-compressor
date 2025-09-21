#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H
#include<memory>
#include<queue>
#include "huffman_queue.h"
struct huffman_node{
    char val;
    int freqCount;
    std::shared_ptr<huffman_node> left;
    std::shared_ptr<huffman_node> right;
    huffman_node(char c);
};

class Huffman_Tree{
    public:
    std::shared_ptr<huffman_node> construct_huffman_tree(std::priority_queue<std::shared_ptr<huffman_node>,std::vector<std::shared_ptr<huffman_node>>,Compare> &q);
};
#endif
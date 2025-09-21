#include "huffman_queue.h"
bool Compare::operator()(const std::shared_ptr<huffman_node> &a,std::shared_ptr<huffman_node> &b){
    return a->freqCount>b->freqCount;
}

std::priority_queue<std::shared_ptr<huffman_node>,std::vector<std::shared_ptr<huffman_node>>,Compare> Huffman_Queue::construct_huffman_queue(uint32_t freqTable[]){
    std::priority_queue<std::shared_ptr<huffman_node>,std::vector<std::shared_ptr<huffman_node>>,Compare> q;
    for(int i=0;i<256;i++){
        if(freqTable[i]==0)continue;
        std::shared_ptr<huffman_node> node = std::make_shared<huffman_node>(static_cast<char>(i));
        node->freqCount = freqTable[i];
        q.push(node);
    }
    return q;
}
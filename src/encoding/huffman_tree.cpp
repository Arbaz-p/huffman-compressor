#include "huffman_tree.h"
huffman_node::huffman_node(char c){
    val=c;
    freqCount=1;
    left=nullptr;
    right=nullptr;
}

std::shared_ptr<huffman_node> Huffman_Tree::construct_huffman_tree(std::priority_queue<std::shared_ptr<huffman_node>,std::vector<std::shared_ptr<huffman_node>>,Compare> &q){
    if(q.empty())return nullptr;
    while(q.size()>1){
        std::shared_ptr<huffman_node> leftNode=q.top();
        q.pop();
        std::shared_ptr<huffman_node> rightNode=q.top();
        q.pop();
        auto internalNode=std::make_shared<huffman_node>('\0');
        internalNode->freqCount=leftNode->freqCount+rightNode->freqCount;
        internalNode->left=leftNode;
        internalNode->right=rightNode;
        q.push(internalNode);
    }
    return q.top();
}
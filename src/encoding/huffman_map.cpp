#include "huffman_map.h"

void Huffman_Map::construct_huffman_map(const std::shared_ptr<huffman_node> &node,std::unordered_map<char,std::pair<uint16_t,uint8_t>> &map,uint16_t number,uint8_t len){
    if(!node)return;
    if(!node->left && !node->right){
        if (len == 0) {
            map[node->val] = {1, 1};
        } else {
            map[node->val] = {number, len};
        }
        return;
    }
    construct_huffman_map(node->left,map,(number<<1|0),len+1);
    construct_huffman_map(node->right,map,(number<<1|1),len+1);
}
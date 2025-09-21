#ifndef WRITE_ENCODED_DATA_H
#define WRITE_ENCODED_DATA_H
#include<fstream>
#include<unordered_map>
#include<stdint.h>
#include<iostream>
class Write_Encoded_Data{
    public:
    int write_data(std::ofstream &out,std::ifstream &in,std::unordered_map<char,std::pair<uint16_t,uint8_t>> &huffman_map);
};
#endif
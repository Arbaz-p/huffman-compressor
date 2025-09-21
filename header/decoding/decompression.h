#ifndef DECOMPRESSION_H
#define DECOMPRESSION_H
#include<fstream>
#include<iostream>
#include<vector>
#include<cstring>
#include "meta_data.h"
#include "extract_meta _data.h"
#include "huffman_queue.h"
#include "huffman_tree.h"
#include "bit_reader.h"
class Decompression{
    public:
        void decompress_data(std::ifstream &in,std::ofstream &out);
};
#endif
#ifndef COMPRESSION_H
#define COMPRESSION_H
#include<fstream>
#include "frequency_table.h"
#include "meta_data.h"
#include "huffman_queue.h"
#include "huffman_tree.h"
#include "huffman_map.h"
#include "write_encoded_data.h"
#include<iostream>
class Compression{
    public:
    void compress_data(std::ifstream &in,std::ofstream &out,std::fstream &fio);
};
#endif
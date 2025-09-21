#ifndef META_DATA_H
#define META_DATA_H
#include<stdint.h>
#include<fstream>
#include<iostream>
struct meta_data
{
    char magic[4];
    uint32_t  freq_table[256];
    uint8_t padding; 
};
class Meta_Data_class{
    public:
    void write_meta_data(std::ofstream &out,meta_data &meta);
    void update_padding(std::fstream &fio,uint8_t pad);
};
#endif
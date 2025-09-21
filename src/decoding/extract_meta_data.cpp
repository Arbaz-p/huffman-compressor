#include "extract_meta _data.h"

meta_data Extract_Meta_Data_Class::extract_meta_data(const std::vector<char> &buffer){
    meta_data meta;
    size_t offset=0;
    memcpy(meta.magic,buffer.data()+offset,sizeof(meta.magic));
    offset+=sizeof(meta.magic);
    memcpy(meta.freq_table,buffer.data()+offset,sizeof(meta.freq_table));
    offset+=sizeof(meta.freq_table);
    memcpy(&meta.padding,buffer.data()+offset,sizeof(meta.padding));
    return meta;
}
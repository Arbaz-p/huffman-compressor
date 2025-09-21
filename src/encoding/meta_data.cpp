#include "meta_data.h"
void Meta_Data_class::write_meta_data(std::ofstream &out,meta_data &meta){
    if(!out.is_open()){
        std::cerr<<"coul not open output file\n";
        return ;
    }
    out.write(reinterpret_cast<char*>(meta.magic),sizeof(meta.magic));
    out.write(reinterpret_cast<char*>(meta.freq_table),sizeof(meta.freq_table));
    out.write(reinterpret_cast<char*>(&meta.padding),sizeof(meta.padding));
}

void Meta_Data_class::update_padding(std::fstream &fio,uint8_t pad){
    fio.seekp(4+256*4,std::ios::beg);
    fio.write(reinterpret_cast<char*>(&pad),sizeof(pad));
}
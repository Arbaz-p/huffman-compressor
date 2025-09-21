#include "compression.h"

void Compression::compress_data(std::ifstream &in,std::ofstream &out,std::fstream &fio){
    uint32_t freq_table[256]={0};
    Frequency_Table ft;
    ft.table(in,freq_table);
    in.clear();
    in.seekg(0,std::ios::beg);
    Huffman_Queue hq;
    auto q=hq.construct_huffman_queue(freq_table);
    Huffman_Tree ht;
    auto root=ht.construct_huffman_tree(q);
    if(!root){
        std::cerr<<"File is empty\n";
        return ;
    }
    std::unordered_map<char,std::pair<uint16_t,uint8_t>> map;
    Huffman_Map hm;
    hm.construct_huffman_map(root,map,0,0);
    meta_data md;
    memcpy(md.magic,"HUFF",4);
    memcpy(md.freq_table,freq_table,sizeof(freq_table));
    md.padding=0;
    Meta_Data_class mdc;
    mdc.write_meta_data(out,md);
    Write_Encoded_Data wed;
    int pad=wed.write_data(out,in,map);
    mdc.update_padding(fio,pad);
    out.flush();
}
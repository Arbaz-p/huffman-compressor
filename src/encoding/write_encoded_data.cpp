#include "write_encoded_data.h"
int Write_Encoded_Data::write_data(std::ofstream &out,std::ifstream &in,std::unordered_map<char,std::pair<uint16_t,uint8_t>> &huffman_map){
    uint8_t bitfilled=0;
    uint8_t buffer=0;
    char ch;
    if(!in){
        std::cerr<<"could not open the file ,cannot write the bits \n";
        return 0;
    }
    while(in.get(ch)){
        auto [code,length]=huffman_map[ch];
        for(int i=length-1;i>=0;i--){
            uint8_t bit=(code>>i) & 1; 
            buffer=(buffer<<1) | bit;
            bitfilled++;
            if(bitfilled==8){
                out.put(buffer);
                buffer=0;
                bitfilled=0;
            }
        }
    }
    if(bitfilled>0){
        buffer=buffer<<8-bitfilled;
        out.put(buffer);
        return 8-bitfilled;
    }
    return 0;
} 
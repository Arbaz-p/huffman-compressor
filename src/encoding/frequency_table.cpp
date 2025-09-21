#include "frequency_table.h"
void Frequency_Table::table(std::ifstream &input,uint32_t freq[]){
    char ch;
    for(int i=0;i<256;i++)freq[i]=0;
    while(input.get(ch))freq[static_cast<unsigned char>(ch)]++;
}
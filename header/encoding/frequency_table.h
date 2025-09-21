#ifndef FREQUENCY_TABLE_H
#define FREQUENCY_TABLE_H
#include<fstream>
#include<stdint.h>
class Frequency_Table
{
public:
    void table(std::ifstream &input,uint32_t freq[]);
};
#endif
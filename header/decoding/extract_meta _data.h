#ifndef EXTRACT_META_DATA_H
#define EXTRACT_META_DATA_H
#include<vector>
#include "meta_data.h"
class Extract_Meta_Data_Class{
    public:
    meta_data extract_meta_data(const std::vector<char> &buffer);
};
#endif
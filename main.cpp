#include "compression.h"
#include "decompression.h"
#include <string>
#include <algorithm>
#include<filesystem>
namespace fs = std::filesystem;
std::string to_lower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::string get_extension(const std::string& filename) {
    size_t dot_pos = filename.find_last_of('.');
    if (dot_pos == std::string::npos) {
        return "";
    }
    return to_lower(filename.substr(dot_pos + 1));
}


int main(int argc,char* argv[]){
    fs::path path=argv[1];
    fs::path absolute_path=fs::absolute(path);
    std::string ext=get_extension(absolute_path.string());
    if(ext=="txt"){
        std::ifstream in(absolute_path);
        absolute_path.replace_extension(".bin");
        std::ofstream out(absolute_path,std::ios::binary);
        std::fstream fio(absolute_path,std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
        Compression c;
        c.compress_data(in,out,fio);
        in.close();
        out.close();
        fio.close();
    }
    else if(ext=="bin"){
        std::ifstream in(absolute_path,std::ios::binary);
        absolute_path.replace_extension(".huff");
        std::ofstream out(absolute_path,std::ios::binary);
        Decompression d;
        d.decompress_data(in,out);
        in.close();
        out.close();
    }
    else{
        std::cerr<<"invalid file ";
    }
    return 0;
}
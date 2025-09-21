#include "decompression.h"

void Decompression::decompress_data(std::ifstream &in, std::ofstream &out) {
    if (!in || !out) {
        std::cerr << "Could not open the file\n";
        return;
    }

    in.seekg(0, std::ios::end);
    size_t fileSize = in.tellg();

    if (fileSize == 0) {
        std::cerr << "Empty file\n";
        return;
    }

    std::vector<char> buffer(fileSize);
    in.seekg(0, std::ios::beg);
    in.read(buffer.data(), fileSize);

    if (!in) {
        std::cerr << "Error reading the file\n";
        return;
    }

    Extract_Meta_Data_Class emd;
    meta_data meta = emd.extract_meta_data(buffer);

    if (strcmp(meta.magic, "HUFF") != 0) {
        std::cerr << meta.magic << " is not a valid compressed file\n";
        return;
    }

    Huffman_Queue hq;
    auto q = hq.construct_huffman_queue(meta.freq_table);
    Huffman_Tree ht;
    auto root = ht.construct_huffman_tree(q);

    constexpr size_t METADATA_SIZE = 4 + 256 * 4 + 1;
    BitReader reader(buffer, METADATA_SIZE);
    reader.extract_bits(out, root, meta.padding);
}

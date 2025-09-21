#include "bit_reader.h"

#include "bit_reader.h"

BitReader::BitReader(const std::vector<char>& buf, size_t i){
    buffer=buf;
    byteIndex=i;
    bitIndex=7;
}

uint8_t BitReader::getNextBit() {
    if (byteIndex >= buffer.size()) return 0; // avoid overflow

    unsigned char byte = buffer[byteIndex];
    uint8_t bit = (byte >> bitIndex) & 1;

    if (bitIndex == 0) {
        bitIndex = 7;
        byteIndex++;
    } else {
        bitIndex--;
    }

    return bit;
}

void BitReader::extract_bits(std::ofstream& out, const std::shared_ptr<huffman_node>& root, int pad) {

    if (!root->left && !root->right) {
        // Read total number of bits (buffer size minus metadata and padding)
        size_t totalBits = (buffer.size() - byteIndex) * 8 - pad;

        // Each bit corresponds to one instance of the only character
        for (size_t i = 0; i < totalBits; ++i) {
            getNextBit(); // discard actual bit, not used
            out.put(root->val);
        }
        return;
    }


    size_t totalBits = (buffer.size() - byteIndex) * 8 - pad;
    size_t bitsRead = 0;
    auto node = root;

    while (bitsRead < totalBits) {
        uint8_t bit = getNextBit();
        bitsRead++;

        node = (bit == 1) ? node->right : node->left;

        if (!node->left && !node->right) {
            out.put(node->val);
            node = root;
        }
    }
}

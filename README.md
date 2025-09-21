# Huffman Compressor (C++)

A lossless file compression and decompression tool implemented in **modern C++** using the **Huffman Coding algorithm**.

This project compresses plain text `.txt` files into compressed binary `.bin` files and decompresses them back into `.huff` files (restored text).

---

## 📌 Features

- ✅ Compress `.txt` files into `.bin` compressed binary format
- ✅ Decompress `.bin` files back into `.huff` restored files
- ✅ Clean, modular C++ code with `CMake` build system
- ✅ Uses **smart pointers (`std::shared_ptr`)** for safe memory management in Huffman tree
- ✅ Efficient Huffman encoding with priority queues and binary trees
- ✅ Handles large text files (10k+ lines) efficiently

---

## 🧠 How It Works

1. Reads the input `.txt` file and calculates character frequencies.
2. Builds a Huffman tree using a priority queue and smart pointers to manage nodes.
3. Encodes the text into a compact binary `.bin` file.
4. Decompressor reads `.bin`, rebuilds the Huffman tree, and outputs the decompressed `.huff` file.

---

## 📁 Project Structure

.
├── CMakeLists.txt # Build configuration
├── main.cpp # Main program entry point
├── src/ # Source code files
│ ├── encoding/ # Encoding (compression) related source files
│ └── decoding/ # Decoding (decompression) related source files
├── header/ # Header files
│ ├── encoding/ # Encoding related headers
│ └── decoding/ # Decoding related headers
├── demo.txt # Sample input text file
├── demo.bin # Compressed binary file
├── demo.huff # Decompressed output file
├── .gitignore # Files ignored by git
└── README.md # Project documentation



 

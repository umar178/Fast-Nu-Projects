#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// --- 1. DSA: Huffman Tree Node Structure ---
// Represents a node in the Huffman tree
struct Node {
    char data;          // Character, only meaningful for leaf nodes
    int freq;           // Frequency of the character
    Node *left, *right; // Pointers to child nodes

    Node(char d, int f, Node* l = nullptr, Node* r = nullptr)
        : data(d), freq(f), left(l), right(r) {}

    // Destructor for cleanup (Crucial DSA practice)
    ~Node() {
        delete left;
        delete right;
    }
};

// --- 2. DSA: Min-Heap Comparator for Priority Queue ---
// Custom comparator for the priority queue to create a Min-Heap based on frequency
struct CompareNode {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // 'a' has higher priority if its frequency is smaller
    }
};

// Typedef for simplicity
typedef priority_queue<Node*, vector<Node*>, CompareNode> MinHeap;

// --- 3. Core Huffman & Helper Functions ---

/**
 * Builds a frequency map from the input file.
 * @param input_filename The path to the file to be read.
 * @param freq_map Output map to store character frequencies.
 * @param total_chars Output variable for total characters read.
 * @return True on success, false on file error.
 */
bool buildFrequencyMap(const string& input_filename, map<char, int>& freq_map, long long& total_chars) {
    ifstream input_file(input_filename, ios::in | ios::binary);
    if (!input_file.is_open()) {
        cerr << "Error: Could not open input file '" << input_filename << "'." << endl;
        return false;
    }

    char ch;
    total_chars = 0;
    while (input_file.get(ch)) {
        freq_map[ch]++;
        total_chars++;
    }

    input_file.close();
    return true;
}

/**
 * DSA: Builds the Huffman tree using a Min-Heap (Priority Queue).
 * @param freq_map The map of character frequencies.
 * @return Pointer to the root of the Huffman tree.
 */
Node* buildHuffmanTree(const map<char, int>& freq_map) {
    MinHeap pq;

    // Create a leaf node for every character and add it to the priority queue
    for (map<char, int>::const_iterator it = freq_map.begin(); it != freq_map.end(); ++it) {
        pq.push(new Node(it->first, it->second));
    }

    // Repeatedly extract two smallest frequency nodes and merge them
    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        // Create a new internal node
        Node* parent = new Node('\0', left->freq + right->freq, left, right);
        pq.push(parent);
    }

    // The last node remaining is the root of the Huffman tree
    if (pq.empty()) {
        return nullptr;
    }
    return pq.top();
}

/**
 * Traverses the Huffman tree to generate Huffman codes for each character.
 * @param root Current node in the tree.
 * @param current_code The binary code string built so far.
 * @param huffman_codes Output map to store char-to-code mapping.
 */
void generateCodes(Node* root, string current_code, map<char, string>& huffman_codes) {
    if (!root) {
        return;
    }

    // Leaf node: store the code
    if (!root->left && !root->right) {
        huffman_codes[root->data] = current_code.empty() ? "0" : current_code;
        return;
    }

    // Traverse left (append '0')
    generateCodes(root->left, current_code + "0", huffman_codes);
    // Traverse right (append '1')
    generateCodes(root->right, current_code + "1", huffman_codes);
}

// --- 4. Encoding/Decoding Utilities (Bitwise I/O) ---

/**
 * Serializes the frequency map into the output stream (the header).
 * Format: [Map Size (int)] -> [Char (1 byte), Freq (int)] * Map Size
 */
void writeHeader(ofstream& outfile, const map<char, int>& freq_map, long long total_chars) {
    // Write the total number of original characters (important for padding/EOF)
    outfile.write((char*)&total_chars, sizeof(total_chars));

    // Write the size of the frequency map (number of unique characters)
    int map_size = freq_map.size();
    outfile.write((char*)&map_size, sizeof(map_size));

    // Write each character and its frequency
    for (map<char, int>::const_iterator it = freq_map.begin(); it != freq_map.end(); ++it) {
        outfile.put(it->first);
        outfile.write((char*)&it->second, sizeof(it->second));
    }
}

/**
 * Deserializes the frequency map from the input stream (the header).
 */
bool readHeader(ifstream& infile, map<char, int>& freq_map, long long& total_chars) {
    // Read total characters
    infile.read((char*)&total_chars, sizeof(total_chars));
    if (infile.fail()) return false;

    // Read map size
    int map_size = 0;
    infile.read((char*)&map_size, sizeof(map_size));
    if (infile.fail()) return false;

    // Read characters and frequencies
    for (int i = 0; i < map_size; ++i) {
        char ch;
        int freq;
        if (!infile.get(ch)) return false;
        if (!infile.read((char*)&freq, sizeof(freq))) return false;
        freq_map[ch] = freq;
    }
    return true;
}

// --- 5. Encoding/Decoding Feature Implementation ---

/**
 * Encodes the input file using the generated Huffman codes.
 */
void encodeFile(const string& input_filename, const string& output_filename,
                const map<char, string>& huffman_codes, long long total_chars,
                const map<char, int>& freq_map) {
    ifstream input_file(input_filename, ios::in | ios::binary);
    ofstream output_file(output_filename, ios::out | ios::binary);

    if (!input_file.is_open() || !output_file.is_open()) {
        cerr << "Error: File opening failed during encoding." << endl;
        return;
    }

    // Write the compression header (DSA: Serialization)
    writeHeader(output_file, freq_map, total_chars);

    // Write the encoded data (DSA: Bitwise operations)
    char buffer = 0; // The 8-bit buffer for packing data
    int bit_count = 0; // Number of bits currently in the buffer
    char ch;

    // Second pass: Read file again and write encoded bits
    while (input_file.get(ch)) {
        string code = huffman_codes.at(ch); // Guaranteed to exist

        for (size_t i = 0; i < code.length(); ++i) {
            // Shift the current buffer left
            buffer <<= 1;

            // If the code bit is '1', set the least significant bit (LSB) of the buffer
            if (code[i] == '1') {
                buffer |= 1;
            }

            bit_count++;

            // If buffer is full (8 bits), write it to the output file
            if (bit_count == 8) {
                output_file.put(buffer);
                buffer = 0;
                bit_count = 0;
            }
        }
    }

    // Handle any remaining bits (padding)
    if (bit_count > 0) {
        // Shift remaining bits to the left to fill the byte and write
        buffer <<= (8 - bit_count);
        output_file.put(buffer);
    }

    input_file.close();
    output_file.close();
    cout << "Encoding complete. Compressed data written to '" << output_filename << "'." << endl;
}

/**
 * Decodes the compressed file back to the original file.
 */
void decodeFile(const string& input_filename, const string& output_filename) {
    ifstream input_file(input_filename, ios::in | ios::binary);
    ofstream output_file(output_filename, ios::out | ios::binary);

    if (!input_file.is_open() || !output_file.is_open()) {
        cerr << "Error: File opening failed during decoding." << endl;
        return;
    }

    map<char, int> freq_map;
    long long total_chars = 0;

    // Read the header and rebuild the frequency map
    if (!readHeader(input_file, freq_map, total_chars)) {
        cerr << "Error: Failed to read header from compressed file." << endl;
        return;
    }

    // Rebuild the Huffman tree (DSA: Tree Reconstruction)
    Node* root = buildHuffmanTree(freq_map);
    Node* current = root;

    if (!root) {
        cerr << "Error: Huffman tree could not be reconstructed." << endl;
        return;
    }

    char byte_in;
    long long decoded_chars = 0;

    // Read the encoded data byte by byte (DSA: Bitwise operations)
    while (input_file.get(byte_in) && decoded_chars < total_chars) {
        // Process 8 bits in the byte
        for (int i = 7; i >= 0 && decoded_chars < total_chars; --i) {
            // Extract the i-th bit from the left (most significant bit first)
            int bit = (byte_in >> i) & 1;

            if (bit == 0) {
                current = current->left;
            } else {
                current = current->right;
            }

            // Check if a leaf node is reached (Decoded a character)
            if (!current->left && !current->right) {
                output_file.put(current->data);
                decoded_chars++;
                current = root; // Reset to the root for the next character
            }
        }
    }

    // Clean up the dynamically allocated tree (DSA: Memory Management)
    delete root;

    input_file.close();
    output_file.close();
    cout << "Decoding complete. Original data restored to '" << output_filename << "'." << endl;
}

/**
 * Calculates and displays the compression ratio.
 */
void displayCompressionStats(const string& original_file, const string& compressed_file) {
    long long original_size = 0;
    long long compressed_size = 0;

    // Get original file size
    ifstream original_f(original_file, ios::binary | ios::ate);
    if (original_f.is_open()) {
        original_size = original_f.tellg();
        original_f.close();
    } else {
        cerr << "Warning: Could not measure original file size." << endl;
        return;
    }

    // Get compressed file size
    ifstream compressed_f(compressed_file, ios::binary | ios::ate);
    if (compressed_f.is_open()) {
        compressed_size = compressed_f.tellg();
        compressed_f.close();
    } else {
        cerr << "Warning: Could not measure compressed file size." << endl;
        return;
    }

    cout << "\n--- Compression Statistics ---" << endl;
    cout << "Original Size: " << original_size << " bytes" << endl;
    cout << "Compressed Size: " << compressed_size << " bytes" << endl;

    if (original_size > 0) {
        double ratio = (double)compressed_size / original_size;
        double savings = (1.0 - ratio) * 100.0;
        cout << "Compression Ratio (Compressed/Original): " << fixed << ratio << endl;
        cout << "Space Savings: " << fixed << savings << "%" << endl;
    } else {
        cout << "Note: Original file is empty, cannot calculate ratio." << endl;
    }
}

// --- 6. Main Program Loop (Interactive Interface) ---

void runEncode() {
    string input_filename = "input.txt";
    string output_filename;

    cout << "\n[ENCODING MODE]" << endl;
    cout << "Input file will be read from: " << input_filename << endl;
    cout << "Enter the output filename for the compressed data (e.g., compressed.huf): ";
    cin >> output_filename;

    map<char, int> freq_map;
    long long total_chars = 0;

    // 1. Build Frequency Map
    if (!buildFrequencyMap(input_filename, freq_map, total_chars)) {
        return;
    }

    if (total_chars == 0) {
        cerr << "Error: Input file is empty. Cannot compress." << endl;
        return;
    }

    // 2. Build Huffman Tree (DSA: Min-Heap/Tree Construction)
    Node* root = buildHuffmanTree(freq_map);

    // 3. Generate Huffman Codes (DSA: Tree Traversal)
    map<char, string> huffman_codes;
    generateCodes(root, "", huffman_codes);

    // 4. Encode File
    encodeFile(input_filename, output_filename, huffman_codes, total_chars, freq_map);

    // 5. Display Stats
    displayCompressionStats(input_filename, output_filename);

    // 6. Cleanup (Memory Management)
    delete root;
}

void runDecode() {
    string input_filename;
    string output_filename;

    cout << "\n[DECODING MODE]" << endl;
    cout << "Enter the input filename (compressed file, e.g., compressed.huf): ";
    cin >> input_filename;
    cout << "Enter the output filename for the restored data (e.g., restored.txt): ";
    cin >> output_filename;

    // Decode File
    decodeFile(input_filename, output_filename);
}

int main() {
    // Note: The __app_id, __firebase_config, and __initial_auth_token are for the execution
    // environment (Canvas) and are not used in this standalone C++ application.

    // Enable sync with C I/O for speed in competitive programming/high-perf, but here
    // it mainly ensures consistent behavior.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int choice = 0;
    
    // Feature: Interactive Menu
    while (choice != 3) {
        cout << "\n========================================" << endl;
        cout << "     HUFFMAN CODING PROJECT (C++)" << endl;
        cout << "========================================" << endl;
        cout << "1. Encode File (Input from input.txt)" << endl;
        cout << "2. Decode File" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cerr << "Invalid input. Exiting." << endl;
            break;
        }

        switch (choice) {
            case 1:
                runEncode();
                break;
            case 2:
                runDecode();
                break;
            case 3:
                cout << "Exiting Huffman Coder. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}

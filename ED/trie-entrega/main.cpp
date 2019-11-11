#include <iostream>
#include <string>
// #include "trie.h"
#include "creating_trie.h"

int main() {
// int main(int argc, char* argv[]) {
    string filename;
    string word;

    std::cin >> filename;  // entrada

    Trie* trie = create_trie(filename);

    while (1) {  // leitura das palavras ate' encontrar "0"
        std::cin >> word;
        if (word.compare("0") == 0) {
            break;
        }

        unsigned long* output = new unsigned long[3];
        output = trie->find(word, output);

        if (output[2] == 0) {
            std::cout << output[0] << " " << output[1] << "\n";
        } else if (output[2] == 1) {
            std::cout << "is prefix\n";
        } else {
            std::cout << "is not prefix\n";
        }
    }
    return 0;
}

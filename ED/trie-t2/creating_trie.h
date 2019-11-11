/* Copyright 2019 Gabriel Simonetto */
#include <iostream>
#include <fstream>
#include <string>
#include "trie.h"

using namespace std;

string extract_word(string line) {
    std::size_t pos = line.find(']');
    return line.substr(1, pos-1);
}

Trie* create_trie(string source) {
    Trie* trie = new Trie(); 
    string line;
    int carryover = 0;

    ifstream myfile (source);
    if (myfile.is_open()) {
        while (getline (myfile,line) ) {
            unsigned long pos = carryover;
            unsigned long length = line.length();
            carryover += length + 1;
            if (line.at(0) != '[') {
                continue;
            }
            string word = extract_word(line);
            trie->insert(word, pos, length);
        }
    myfile.close();
    }

    return trie;
}

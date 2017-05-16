#ifndef COMPRESSION_INSTANCE_H
#define COMPRESSION_INSTANCE_H
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <unordered_set>
#include <string.h>
#include <unistd.h>

using namespace std;

class Compression_Instance
{
    public:
        Compression_Instance(string &filename);
        ~Compression_Instance();
        void print_letter_heuristics();
        void build_meta_data();

    private:
        void build_letter_map();
        void evaluate_chars();
        bool order_chars(const string a, const string b);

        map<char,uint> m_letter_heuristics;
        vector<char> *m_ordered_chars;
        const char *m_original_text;
};

#endif // COMPRESSION_INSTANCE_H

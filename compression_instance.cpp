#include "compression_instance.h"

Compression_Instance::Compression_Instance(string &filename) {
    string filepath = "/home/nick/projects/SimpleCompression/TextFiles/";
    filepath = filepath + filename + ".txt";
    ifstream file (filepath);
    if(file.is_open()) {
        uint buf_size = 0;
        while(file.get() != -1) {
            ++buf_size;
        }
        char *buf = (char *)calloc(buf_size, sizeof(char));
        file.clear();
        file.seekg(0, ios::beg);
        for(uint i = 0; i < buf_size; ++i) {
            char curr_char = file.get();
//            transform(curr_char, curr_char, curr_char, ::tolower);
            curr_char = tolower(curr_char);
            m_letter_heuristics[curr_char]++;
            buf[i] = curr_char;
        }
        m_original_text = buf;
        file.close();
    } else {
        cout << "Unable to open file: " << filepath << endl;
    }
}

Compression_Instance::~Compression_Instance() {

}

void Compression_Instance::print_letter_heuristics() {
    for (map<char,uint>::iterator it=m_letter_heuristics.begin(); it!=m_letter_heuristics.end(); ++it) {
        cout << it->first << " => " << it->second << '\n';
    }
}

void Compression_Instance::build_meta_data() {
    build_letter_map();
}

void Compression_Instance::build_letter_map() {
    m_ordered_chars = new vector<char>(m_letter_heuristics.size(),' ');
    uint index = 0;
    for (map<char,uint>::iterator it=m_letter_heuristics.begin(); it!=m_letter_heuristics.end(); ++it) {
        (*m_ordered_chars)[index++] = it->first;
    }
    sort(m_ordered_chars->begin(), m_ordered_chars->end(),
         [this] (const char a, const char b) {
            return this->m_letter_heuristics[a] > this->m_letter_heuristics[b];
         }
    );
    for(uint i = 0; i < m_ordered_chars->size(); ++i) {
        cout << (*m_ordered_chars)[i] << endl;
    }
    cout << endl << m_ordered_chars->size() << endl;
}

void Compression_Instance::evaluate_chars() {
    uint num_chars = m_ordered_chars->size();
}






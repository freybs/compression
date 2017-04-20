#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <string.h>
#include <unistd.h>

#define SIZE_BYTE 8
#define LSB_MASK 0x01

using namespace std;

uint  pre_process_file_for_compression(string &filename, map<string,int> &letter_heuristics, char **buf);

int main(int argc, char *argv[]) {
    printf("COMPRESS!\nInput file name: ");
    string filename;
    getline(cin,filename);

    map<string,int> letter_heuristics;
    char *original_text;

    pre_process_file_for_compression(filename, letter_heuristics, &original_text);

    for (map<string,int>::iterator it=letter_heuristics.begin(); it!=letter_heuristics.end(); ++it)
        cout << it->first << " => " << it->second << '\n';

//    printf("%s\n", original_text);
    return 0;
}

uint pre_process_file_for_compression(string &filename, map<string,int> &letter_heuristics, char **buf) {
    string filepath = "/home/nick/projects/SimpleCompression/TextFiles/";
    uint char_cnt = 0;
    filepath = filepath + filename + ".txt";
    ifstream file (filepath);
    if(file.is_open()) {
        uint buf_size = 0;
        while(file.get() != -1) {
            ++buf_size;
        }
        *buf = (char *)calloc(buf_size, sizeof(char));
        file.clear();
        file.seekg(0, ios::beg);
        char curr_char;
        string curr_char_as_string = "a";
        for(uint i = 0; i < buf_size; ++i) {
            curr_char = file.get();
            curr_char_as_string[0] = curr_char;
            letter_heuristics[curr_char_as_string]++;
            (*buf)[i] = curr_char;
        }
        file.close();
    } else {
        cout << "Unable to open file: " << filepath << endl;
    }
    return char_cnt;
}

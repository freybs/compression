#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <string.h>
#include <unistd.h>
#include "compression_instance.h"

#define SIZE_BYTE 8
#define LSB_MASK 0x01

using namespace std;

int main(int argc, char *argv[]) {
    cout << "COMPRESS!\nInput file name: ";
    string filename;
    getline(cin,filename);

    try{
        Compression_Instance *compr = new Compression_Instance(filename);
        compr->print_letter_heuristics();
        compr->build_meta_data();
        delete(compr);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}

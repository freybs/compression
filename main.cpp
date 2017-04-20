#include <iostream>
#include <string>

#define SIZE_BYTE 8
#define LSB_MASK 0x01

#define ASCII_0 0x30
#define ASCII_9 0x39
#define ASCII_A 0x41
#define ASCII_Z 0x5A
#define ASCII_a 0x61
#define ASCII_z 0x7A
#define ASCII_p 0x2E
#define ASCII_c 0x2C

#define NICKSCII_0 0x00
#define NICKSCII_9 0x09
#define NICKSCII_A 0x0A
#define NICKSCII_Z 0x23
#define NICKSCII_a 0x24
#define NICKSCII_z 0x3D
#define NICKSCII_p 0x3E
#define NICKSCII_c 0x3F

using namespace std;

bool *string_to_bool(string &in);
bool *char_to_bool(char letter);
void compress_string(string &in);
void ascii_to_nickscii(string &in, char *out);

int main(int argc, char *argv[]) {
    cout << "COMPRESS!" << endl;
    string word;
    while(true) {
        getline (cin, word);
        if(word.compare("") == 0) {
            break;
        }
        compress_string(word);
    }
    return 0;
}

void compress_string(string &in) {

}

void ascii_to_nickscii(string &in, char *out) {
    uint length = in.size();
    uint num_ascii_bits = length * 8;
    uint num_nickscii_bits = num_ascii_bits * 3 / 4;
    uint num_nickscii_chars = (num_nickscii_bits / 8) + (num_nickscii_bits % 8) ? 1 : 0;
    char *nickscii_string = new char[num_nickscii_chars];
}

bool *string_to_bool(string &in) {
    char letter;
    for(uint i = 0; i < in.size(); ++i){
        letter = in[i];
        bool *foo = char_to_bool(letter);
        for(int j = 7; j >= 0; --j) {
            cout << foo[j];
        }
        cout << endl;
    }

}

bool *char_to_bool(char letter) {
    char masked;
    bool *binary = new bool[SIZE_BYTE];
    for(uint i = SIZE_BYTE - 1; i >= 0; --i) {
        masked = letter & (LSB_MASK<<(i));
        binary[i] = (bool)masked;
    }
    return binary;
}

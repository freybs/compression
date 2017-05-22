#ifndef COMPRESSION_INSTANCE_H
#define COMPRESSION_INSTANCE_H

#include <string>
#include <map>
#include <vector>
#include <unordered_set>
#include <unistd.h>

using namespace std;

class Compression_Instance
{
	public:
		Compression_Instance(string &filename);
		~Compression_Instance();
		void print_letter_heuristics();
		void print_case_insensitive_letter_heuristics();
		void build_meta_data();

	private:
		void build_ordered_chars();
		void build_letter_map();
		void evaluate_chars();
		bool order_chars(const string a, const string b);

		map<char,uint> *m_letter_heuristics;
		map<char,uint> *m_lower_letter_heuristics;
		vector<char> *m_ordered_chars;
		char *m_original_text;

		// Meta data for output
		char **m_letter_map;
		char  *m_char_type_lens;
		uint   m_num_char_types;
};

#endif // COMPRESSION_INSTANCE_H

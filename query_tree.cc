// Jason Chen
// Main file for Part2(a) of Homework 2.
// Code will compile and run after you have completed sequence_map.h.

#include "avl_tree.h"
#include "sequence_map.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

namespace {


// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree) {
	// Code for running Part2(a)
	// Parse input file @db_filename and feel tree @a_tree
	// Then prompt the user for exactly three strings (do a loop) and
	// provide the results of find() as described in the assignment.
	
	//opening the file
	std::ifstream input_file;
	input_file.open(db_filename);
	if(input_file.fail()){
		cout << "FILE FAILED TO OPEN" << endl;
		exit(1);
	}

	
	std::string db_line;
	while(getline(input_file, db_line)){
		std::stringstream ss_db_line(db_line);
		std::string an_enz_acro;
		std::string a_reco_seq;

		getline(ss_db_line, an_enz_acro, '/');
		while(getline(ss_db_line, a_reco_seq)){
			SequenceMap new_sequence_map(a_reco_seq, an_enz_acro);
			a_tree.insert(new_sequence_map);
		
		}
	}
	input_file.close();
	std::string userinput_sentences;
	cout << "Enter Recognition Sequences" << endl;
	while(cin >> userinput_sentences){
		SequenceMap query{userinput_sentences, ""};
		if(a_tree.contains(query)) {
            
            
		}
		else{
			std::cout << "Not Found" << std::endl;
		}
	}
}

}  // namespace

int
main(int argc, char **argv) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
		return 0;
	}
	const string db_filename(argv[1]);
	
	cout << "Input filename is " << db_filename << endl;
	AvlTree<SequenceMap> a_tree;
	QueryTree(db_filename, a_tree);

	return 0;
}

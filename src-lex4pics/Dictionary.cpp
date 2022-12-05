/*
 * Dictionary.cpp
 *
 *  Created on: Jan 25, 2012
 *      Author: rui
 */
#include "Dictionary.h"
//#include <iostream>
//#include <string>
//using namespace std;

Dictionary::Dictionary() {
	// TODO Auto-generated constructor stub

}

Dictionary::~Dictionary() {
	// TODO Auto-generated destructor stub
}

long Dictionary::get_actual_table_length(){
	return actual_table_length;
}

void Dictionary::set_actual_table_length(long n){
	actual_table_length = n;
}

string Dictionary::get_dict_table(long i){
	return dict_table[i];
}

void Dictionary::set_dict_table(){
	string dictfilename = "dictionary.dat";
	ifstream infile;
	infile.open("dictionary.dat", ios::in);
	if (! infile){
		cerr<<"open dictionary error!"<<endl;
		//exit(1);
	}
	for (long i=0; i<MAX_TABLE_LENGTH; i++){
		infile>>dict_table[i];
		if (dict_table[i].length() == 0){
			actual_table_length = i;
			break;
		}
	}
	cout<<"The dictionary includes "<<actual_table_length<<" words."<<endl;
	//cout<<dict_table[actual_table_length-1]<<endl;
	infile.close();
}

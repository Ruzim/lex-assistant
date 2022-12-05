/*
 * Dictionary.h
 *
 *  Created on: Jan 25, 2012
 *      Author: rui
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX_TABLE_LENGTH 200000
class Dictionary {
private:
	long actual_table_length;
	string dict_table[MAX_TABLE_LENGTH];
public:
	Dictionary();
	virtual ~Dictionary();
	long get_actual_table_length();
	void set_actual_table_length(long n);
	string get_dict_table(long i);
	void set_dict_table();
};

#endif /* DICTIONARY_H_ */

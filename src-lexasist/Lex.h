/*
 * Lex.h
 *
 *  Created on: Jan 25, 2012
 *      Author: rui
 */

#ifndef LEX_H_
#define LEX_H_
#include "Dictionary.h"
#include "Tiles.h"
#include <iostream>
//#include <fstream>
#include <string>
using namespace std;

#define MAX_WORDS_IN_POOL 10000
#define SHORTEST_WORD_LENGTH 5
class Lex {
private:
	Dictionary dict;
	Tiles tiles;
	string pool0[MAX_WORDS_IN_POOL]; //store the words that can be found in the tiles (length >=5)
	string pool1[MAX_WORDS_IN_POOL]; //store the words that can be found in the tiles except 1 characters (length >=6)
	string pool2[MAX_WORDS_IN_POOL]; //store the words that can be found in the tiles except 2 characters (length >=7)
	string pool3[MAX_WORDS_IN_POOL]; //store the words that can be found in the tiles except 3 characters (length >=8)
	string pool4[MAX_WORDS_IN_POOL]; //store the words that can be found in the tiles except 4 characters (length >=9)
	int num_in_pool0;
	int num_in_pool1;
	int num_in_pool2;
	int num_in_pool3;
	int num_in_pool4;

	int threshold_pool0; // only the words longer than the threshold will be put in the pool
	int threshold_pool1;
	int threshold_pool2;
	int threshold_pool3;
	int threshold_pool4;

public:
	Lex();
	virtual ~Lex();
	void prepare();
	void compare();
	void add_word_to_pool0(string word);
	void add_word_to_pool1(string word);
	void add_word_to_pool2(string word);
	void add_word_to_pool3(string word);
	void add_word_to_pool4(string word);
	void sort_pools();
	void display();
	void output_pools();
};

#endif /* LEX_H_ */

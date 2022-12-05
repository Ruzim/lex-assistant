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

#define MAX_WORDS_IN_POOL 5000
#define SHORTEST_WORD_LENGTH 5
class Lex {
private:
	Dictionary dict;
	Tiles tiles;
	int num_letters; //number of letters for the word
	string pool0[MAX_WORDS_IN_POOL]; //store the words that can be found in the tiles (length=num_letters)
	
	int num_in_pool0;

public:
	Lex();
	virtual ~Lex();
	void input();
	void prepare();
	void compare();
	void add_word_to_pool0(string word);
	void sort_pools();
	void display();
	void output_pools();
};

#endif /* LEX_H_ */

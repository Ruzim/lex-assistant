/*
 * Lex.cpp
 *
 *  Created on: Jan 25, 2012
 *      Author: rui
 */

#include "Lex.h"

Lex::Lex() {
	// TODO Auto-generated constructor stub
	num_in_pool0 = 0;
	num_in_pool1 = 0;
	num_in_pool2 = 0;
	num_in_pool3 = 0;
	num_in_pool4 = 0;
	threshold_pool0 = 6;
	threshold_pool1 = 8;
	threshold_pool2 = 10;
	threshold_pool3 = 12;
	threshold_pool4 = 14;
}

Lex::~Lex() {
	// TODO Auto-generated destructor stub
}

void Lex::prepare(){
	dict.set_dict_table();
	tiles.set_tiles_str();
}

void Lex::compare(){
	string tile_store = tiles.get_tiles_str();
	int tiles_length = tiles.get_num_tiles();
	int tiles_status[100];
	for (int i=0; i<=100-1; i++){tiles_status[i]=0;}
		// status 0 : available
		// status 1 : used
		// status 2 : unavailable
	int j,k;

	int word_length = 0;
	for (long i=0; i<=dict.get_actual_table_length()-1; i++){
		string word = dict.get_dict_table(i);
		for (int m=0; m<=tiles_length-1; m++){tiles_status[m]=0;}// initiate tiles intact
		word_length = word.length();
		if (word_length < SHORTEST_WORD_LENGTH) continue; // don't treat short words in the dictionary (len<=3)
		int n_match = 0;
		for (j=0; j<=word_length-1; j++){
			for (k=0; k<=tiles_length-1; k++){
				if (tiles_status[k]!=0){
					continue;
				} else {
					if (tile_store[k]==word[j]){//found 1 character in the tiles.
						n_match++;
						tiles_status[k]=1;
						break;
					}
				}
			}
		}
		int n_unmatch = word_length - n_match;
		switch (n_unmatch){
		case 0:
			if (word_length >= threshold_pool0){
				//cout<<"match word found!     "<<word<<endl;
				add_word_to_pool0(word);
			}

			break;
		case 1:
			if (word_length >= threshold_pool1){
				//cout<<"word missing 1 char!  "<<word<<endl;
				add_word_to_pool1(word);
			}
			break;
		case 2:
			if (word_length >= threshold_pool2){
				//cout<<"word missing 2 char!  "<<word<<endl;
				add_word_to_pool2(word);
			}
			break;
		case 3:
			if (word_length >= threshold_pool3){
				//cout<<"word missing 3 char!  "<<word<<endl;
				add_word_to_pool3(word);
			}
			break;
		case 4:
			if (word_length >= threshold_pool4){
				add_word_to_pool4(word);
			}
			break;
		default: break;
		}
	}
	//debug:
	//string word = dict.get_dict_table(2);
	//word_length = word.length();
	//cout<<word<<"   "<<word_length<<endl;
	// Then sort in pools:
	cout<<"***************************************************"<<endl;
	cout<<"NO. matched words:  "<<num_in_pool0;
	cout<<"   @length >="<<threshold_pool0<<endl;
	cout<<"NO. words missing 1 char:  "<<num_in_pool1;
	cout<<"   @length >="<<threshold_pool1<<endl;
	cout<<"NO. words missing 2 chars: "<<num_in_pool2;
	cout<<"   @length >="<<threshold_pool2<<endl;
	cout<<"NO. words missing 3 chars: "<<num_in_pool3;
	cout<<"   @length >="<<threshold_pool3<<endl;
	cout<<"NO. words missing 4 chars: "<<num_in_pool4;
	cout<<"   @length >="<<threshold_pool4<<endl;
	cout<<"***************************************************"<<endl;
}

void Lex::add_word_to_pool0(string word){
	if (num_in_pool0 < MAX_WORDS_IN_POOL){
		pool0[num_in_pool0] = word;
		num_in_pool0++;
	} else {
		cout<<"Pool 0 exceeded!"<<endl;
	}
}

void Lex::add_word_to_pool1(string word){
	if (num_in_pool1 < MAX_WORDS_IN_POOL){
		pool1[num_in_pool1] = word;
		num_in_pool1++;
	} else {
		cout<<"Pool 1 exceeded!"<<endl;
	}
}

void Lex::add_word_to_pool2(string word){
	if (num_in_pool2 < MAX_WORDS_IN_POOL){
		pool2[num_in_pool2] = word;
		num_in_pool2++;
	} else {
		cout<<"Pool 2 exceeded!"<<endl;
	}
}

void Lex::add_word_to_pool3(string word){
	if (num_in_pool3 < MAX_WORDS_IN_POOL){
		pool3[num_in_pool3] = word;
		num_in_pool3++;
	} else {
		cout<<"Pool 3 exceeded!"<<endl;
	}
}

void Lex::add_word_to_pool4(string word){
	if (num_in_pool4 < MAX_WORDS_IN_POOL){
		pool4[num_in_pool4] = word;
		num_in_pool4++;
	} else {
		cout<<"Pool 4 exceeded!"<<endl;
	}
}

void Lex::sort_pools(){
	// sort the words in each pool;
	// longest words at top;
	void bubble_sort(string[], int);
	bubble_sort(pool0, num_in_pool0);
	bubble_sort(pool1, num_in_pool1);
	bubble_sort(pool2, num_in_pool2);
	bubble_sort(pool3, num_in_pool3);
	bubble_sort(pool4, num_in_pool4);
}

void bubble_sort(string array[], int n){
	// sort the words in each pool;
	// longest words at top;
	// bubble sort;
	int flag;
	string temp;
	for (int i = 0; i < n-1; i++){
		flag = 1;
		for (int j = 0; j < n-1-i; j++){
			if (array[j].length() < array[j+1].length()){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				flag = 0;
			}
		}
		if(flag == 1){
			//cout<<i<<endl;
			break;
		}
	}
}

void Lex::display(){
	cout<<"Longest 10 matched words:  ";
	cout<<"length >="<<threshold_pool0<<endl;
	//for (int i=0; i<=num_in_pool0-1; i++){
	//	cout<<pool0[i]<<"   "<<endl;
	//}
	for (int i=0; i<=10; i++){
		cout<<pool0[i]<<"   "<<endl;
	}
	cout<<endl;

	/*cout<<"Words missing 1 letter:  ";
	cout<<"length >="<<threshold_pool1<<endl;
	for (int i=0; i<=num_in_pool1-1; i++){
		cout<<pool1[i]<<"   "<<endl;
	}
	cout<<endl;

	cout<<"Words missing 2 letters:  ";
	cout<<"length >="<<threshold_pool2<<endl;
	for (int i=0; i<=num_in_pool2-1; i++){
		cout<<pool2[i]<<"   "<<endl;
	}
	cout<<endl;

	cout<<"Words missing 3 letters:  ";
	cout<<"length >="<<threshold_pool3<<endl;
	for (int i=0; i<=num_in_pool3-1; i++){
		cout<<pool3[i]<<"   "<<endl;
	}
	cout<<endl;

	cout<<"Words missing 4 letters:  ";
	cout<<"length >="<<threshold_pool4<<endl;
	for (int i=0; i<=num_in_pool4-1; i++){
		cout<<pool4[i]<<"   "<<endl;
	}
	cout<<endl;*/
}

void Lex::output_pools(){
	cout<<"Output to files......  "<<endl;
	ofstream outfile;
	outfile.open("pool0.txt",ios::out);
	outfile<<"Matched words:  ";
	outfile<<"length >="<<threshold_pool0<<endl;
	for (int i=0; i<=num_in_pool0-1; i++){
		outfile<<pool0[i]<<endl;
	}
	outfile.close();

	outfile.open("pool1.txt",ios::out);
	outfile<<"Words missing 1 letter:  ";
	outfile<<"length >="<<threshold_pool1<<endl;
	for (int i=0; i<=num_in_pool1-1; i++){
		outfile<<pool1[i]<<endl;
	}
	outfile.close();

	outfile.open("pool2.txt",ios::out);
	outfile<<"Words missing 2 letters:  ";
	outfile<<"length >="<<threshold_pool2<<endl;
	for (int i=0; i<=num_in_pool2-1; i++){
		outfile<<pool2[i]<<endl;
	}
	outfile.close();

	outfile.open("pool3.txt",ios::out);
	outfile<<"Words missing 3 letters:  ";
	outfile<<"length >="<<threshold_pool3<<endl;
	for (int i=0; i<=num_in_pool3-1; i++){
		outfile<<pool3[i]<<endl;
	}
	outfile.close();

	outfile.open("pool4.txt",ios::out);
	outfile<<"Words missing 4 letters:  ";
	outfile<<"length >="<<threshold_pool4<<endl;
	for (int i=0; i<=num_in_pool4-1; i++){
		outfile<<pool4[i]<<endl;
	}
	outfile.close();
	cout<<"See files poolx.txt for more details."<<endl;
}

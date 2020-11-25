#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <string>

#include "encrypt.h"

namespace text{
	std::ofstream file;
	std::ifstream file_in;	
};

namespace key{
	std::ofstream file;
	std::ifstream file_in;
};
/*
TODO:
3) also fix the problem with the input file names plz 
4) also get the equivalent of sys.argv 
*/
int Encrypt::random(){
	int random_number = rand()%10;
	int signed_chance = rand()%2;

	if (signed_chance){
		random_number = -random_number;
	};

	return random_number;
}

std::vector <char> Encrypt::decode_text(std::string &filename){
	std::vector <char> decoded_text;
	std::string decoded_temp;
	text::file_in.open(filename,std::ios::in);
	text::file_in >> decoded_temp;
	
	for (char temp : decoded_temp){
		decoded_text.push_back(temp);
	}
	return decoded_text;
}

std::vector <std::string> Encrypt::decode_key(std::string &key){
	std::vector <std::string> decoded_key;
	std::string decoded_temp;
	key::file_in.open(key,std::ios::in);
	key::file_in >> decoded_temp;
	std::string temp;
	for (char i : decoded_temp){
		if (i == '-'){
			temp += i;
		}
		else {
		temp += i;
		decoded_key.push_back(temp);
		temp.clear();
	}
	}
	return decoded_key;
}

void Encrypt::encrypt(std::string filename, std::string text){
	std::string encrypted_text, key;
	
	for (char i : text){
		short int random_number = Encrypt::random();
		short int value = (short int) (i) - random_number;
		encrypted_text += char(value);
		key += std::to_string (random_number); 
	}

	text::file.open(filename +".enc", std::ios::out);
	text::file << encrypted_text;
	text::file.close();
	key::file.open(filename + "_key.enc", std::ios::out);
	key::file << key;
	key::file.close();

	}

void Encrypt::decrypt(std::string filename, std::string key){
	std::vector <char> dec_text;
	std::vector <std::string> dec_key;
	std::string output,key_value;
	char ascii_text;
	int value;

	dec_text = Encrypt::decode_text(filename);
	dec_key = Encrypt::decode_key(key);
	
	for (int i=0; i < dec_key.size(); i++){
		key_value = dec_key.at(i); 
		ascii_text = dec_text.at(i);
		value = (int) ascii_text + std::stoi (key_value);  
		
		output += char(value);
	}

		std::cout << output << std::endl; 	

	}

void Encrypt::encrypt_file(std::string name){
	std::string text,temp;
	text::file_in.open(name,std::ios::in);
	while (getline(text::file_in,temp)){
		text += temp;
	}
	Encrypt::encrypt(name,text);
}

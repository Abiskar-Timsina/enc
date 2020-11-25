#include <iostream>
#include <string>

#include "encrypt.h"

int main(int argc, char* argv[]){
	std::string filename,text;
	Encrypt *enc = new Encrypt;
	
	try{
		if (argc > 2){
			enc->decrypt(argv[1],argv[2]);
			return 0;
		}

		else if (argc == 2){
			enc->encrypt_file(argv[1]);
			return 0;
		}

	}
	catch(int error){
	std::cout << "[ERROR] No <filename>_key.enc file given." << std::endl;
	return 0;
	}

	std::cout << "Enter the filename: ";
	getline(std::cin,filename);
	std::cout << std::endl;
	std::cout << "Enter the text: ";
	std::cin.clear();
	getline(std::cin, text);

	enc->encrypt(filename,text);
	return 0;

}

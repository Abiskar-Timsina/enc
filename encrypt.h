#ifndef ENCRYPT
#define ENCRYPT 
#include <vector>
class Encrypt{
	int random();
	std::vector<char> decode_text(std::string&);
	std::vector <std::string> decode_key(std::string&);
	public:
	void encrypt(std::string,std::string);
	void decrypt(std::string,std::string);
	void encrypt_file(std::string);
};


#endif

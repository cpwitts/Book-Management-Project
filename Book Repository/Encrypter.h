#pragma once
#ifndef ENCRYPTER_H
#define ENCRYPTER_H
#include <string>

//A class with static functions for encrypting/decrypting strings
class Encrypter
{
	static const int encryptionValue = 4; //Used for encryption/decryption

public:

	/**
	Encrypts a string using the Caesar cipher method
	@param string The string to be encrypted
	@return string The encrypted string
	*/
	static std::string encryptString(std::string stringParam);

	/**
	Decrypts a string using the Caesar cipher method
	@param string The string to be decrypted
	@return string The decrypted string
	*/
	static std::string decryptString(std::string stringParam);


};

#endif
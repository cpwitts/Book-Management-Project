#include "Encrypter.h"
#include <iostream>

std::string Encrypter::encryptString(std::string stringParam)
{
	std::string returnString = "";

	/*
	For each character in stringParam, encrypt the character, following 5 steps.
	It is assumed the character is a letter.
	1. The character is first converted to AISCII (by casting to int).
	2. This value is changed by adding encryptionValue, so it becomes another character.
	3. The value is then reduced by the ascii value for 'a' or 'A' (depending on case).
	4. This value undergoes a modulo operation to ensure that it is cyclical,
	i.e. 'Y' (89) with encryptionValue 4 becomes 'C'(67), not ']'(93).
	5.The value is then increased by the same value it was reduced by in step 3,
	so that the value matches that of an ascii letter.
	*/
	for (char & c : stringParam)
	{
		if (islower(c))
		{
			c = ((((int)c + encryptionValue) - 97) % 26) + 97;
		}
		else
		{
			c = ((((int)c + encryptionValue) - 65) % 26) + 65;
		}

		returnString += c;
	}
	return returnString;
}

std::string Encrypter::decryptString(std::string stringParam)
{
	std::string returnString = "";

	/*
	For each character in stringParam, decrypt the character, following 5 steps.
	It is assumed the character is a letter.
	1. The character is first converted to AISCII (by casting to int).
	2. This value is changed by adding deducting encryptionValue, so it becomes another character.
	3. The value is then reduced, so that 'A' and 'a' become the numeric value 1.
	4. If the value is now negative, it is increased by 26 to make it a cyclical alpahbet.
	i.e. 'B' (66) with a encryptionValue of 4 would end as '>' (62), when it should go to 'X' (88).
	5.The value is then increased by the same value it was reduced by in step 3,
	so that the value matches that of an aiscii letter.
	*/
	for (char & c : stringParam)
	{
		if (islower(c))
		{
			c = (((int)c - encryptionValue) - 97);
			if (c < 0)
			{
				c = (int)c + 26;
			}
			c = (int)c + 97;
		}
		else
		{
			c = (((int)c - encryptionValue) - 65);
			if (c < 0)
			{
				c = (int)c + 26;
			}
			c = (int)c + 65;
		}

		returnString += c;
	}

	return returnString;
}



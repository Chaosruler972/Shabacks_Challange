#include "TopSecretLib.h"
#include "Encryption.h"
#include <iostream>
#include <string>
#include <map>
BinaryBuffer GetEncryptedBuffer()
{
	unsigned int i;
	std::string str = "Password";
	for (i = 0; i < str.length(); i++)
	{
		str[i] += 1;
	}
	
	if (str[4] != 120)
	{
		return SomeFunction9936(); // GetEncryptionKey v1
	}
	else
	{
		return SomeFunction145(); // GetEncryptedPassword
	}
}

BinaryBuffer GetEncryptionKey()
{
	short i = 15;
	short c = i % 6;
	if (c > 6)
	{
		return SomeFunction1839(); // GetEncryptionKey v2 
	}
	std::vector<char> v;
	for (; i < 100; ++i)
	{
		v.emplace_back(i);
	}

	return (v.size() > 80) ? SomeFunction1362() : SomeFunction4932(); // v.size > 80 GetEncryptionKey v3 // v.size <= 80 GetEncryptionKey v4  
}

void main()
{

	 BinaryBuffer encryptedBuffer = GetEncryptedBuffer();
	 BinaryBuffer encryptionKey = GetEncryptionKey();
	 BinaryBuffer passwordBinary = Decrypt(encryptedBuffer, encryptionKey);
	 std::string password(passwordBinary.cbegin(), passwordBinary.cend());
			
	std::cout << password << std::endl;
	int x;
	std::cin >> x;
}
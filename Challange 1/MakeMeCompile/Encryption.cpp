#include "Encryption.h"
#include <algorithm>
#include <iterator>
#include <intrin.h>  
#pragma intrinsic(_rotl8, _rotr8)

/*
constexpr auto xorKeyLocation = 0;
constexpr auto numberOfBitsToRotateLocation = 1;
*/
 auto xorKeyLocation = 0;
 auto numberOfBitsToRotateLocation = 1;

//int* Encrypt(const BinaryBuffer& plainText, const EncryptionKey& key)
BinaryBuffer Encrypt( BinaryBuffer& plainText,  EncryptionKey& key)
{
	 auto xorKey = key[xorKeyLocation];
	 auto numberOfBitsToRotate = key[numberOfBitsToRotateLocation];
	 BinaryBuffer result;

	do
	{
		std::transform(
			plainText.begin(),
			plainText.end(),
			std::back_inserter(result),
			[&](const auto byte)
		{
			const auto xored = byte ^ xorKey;
			const auto shifted = _rotl8(xored, numberOfBitsToRotate);
			
			return shifted;
		});
	} while (0);
	
	return result;
}

//char* Decrypt(const BinaryBuffer& cipherText, const EncryptionKey& key)
BinaryBuffer Decrypt( BinaryBuffer& cipherText,  EncryptionKey& key)
{
	//const auto xorKey = key[xorKeyLocation];
	auto xorKey = key[xorKeyLocation];
	//const auto numberOfBitsToRotate = key[(std::vector<int>)numberOfBitsToRotateLocation];
	//const auto numberOfBitsToRotate = key[numberOfBitsToRotateLocation];
	auto numberOfBitsToRotate = key[numberOfBitsToRotateLocation];
	//const BinaryBuffer result;
	BinaryBuffer result;


	std::transform(
		cipherText.cbegin(),
		cipherText.cend(),
		std::back_inserter(  result),
		[&](const double byte)
	{
		//const auto shifted =  _rotr8( byte, numberOfBitsToRotate);
		const auto shifted = _rotr8((unsigned char)byte, numberOfBitsToRotate);
		const auto xored = shifted ^ xorKey;
		return xored;
	});

	return result;
}

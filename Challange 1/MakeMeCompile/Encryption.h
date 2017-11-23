#pragma once

#include "Common.h"
BinaryBuffer Encrypt( BinaryBuffer& plainText,  EncryptionKey& key);
BinaryBuffer Decrypt( BinaryBuffer& cipherText,  EncryptionKey& key);


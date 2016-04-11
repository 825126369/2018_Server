/*
 * EncryptionManager.h
 *
 *  Created on: Apr 10, 2016
 *      Author: xuke
 */

#ifndef SRC_ENCRYPTIONMANAGER_ENCRYPTIONMANAGER_H_
#define SRC_ENCRYPTIONMANAGER_ENCRYPTIONMANAGER_H_

#include <openssl/aes.h>
#include <cstdio>
#include <cstring>
#include <iostream>
namespace basic {

class EncryptionManager {
public:
	EncryptionManager();
	virtual ~EncryptionManager();
};

class Encryption_AES:public EncryptionManager
{
public:
	unsigned char* Encryption(const unsigned char* inputStream,const unsigned char* key,const unsigned char* iv);
	unsigned char* Decryption(const unsigned char* inputStream,const unsigned char* key,const unsigned char* iv);

	int GetCipherLength(int inputLength);
	int GetStreamLength(const unsigned char* Stream,int inputLength);
	unsigned char* Encryption_CBC(const unsigned char* inputStream,int len,unsigned char* keyStr,unsigned char* iv);
	unsigned char* Decryption_CBC(const unsigned char* inputStream,int len,unsigned char* keyStr,unsigned char* iv);

	unsigned char* Encryption_ECB(const unsigned char* inputStream,const unsigned char* key,unsigned char* iv);
	unsigned char* Decryption_ECB(const unsigned char* inputStream,const unsigned char* key,unsigned char* iv);
	static Encryption_AES* getSingle();
private:
	//static Encryption_AES* single;

};

} /* namespace basic */

#endif /* SRC_ENCRYPTIONMANAGER_ENCRYPTIONMANAGER_H_ */

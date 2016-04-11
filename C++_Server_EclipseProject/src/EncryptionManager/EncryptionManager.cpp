/*
 * EncryptionManager.cpp
 *
 *  Created on: Apr 10, 2016
 *      Author: xuke
 */

#include "../EncryptionManager/EncryptionManager.h"

namespace basic {

EncryptionManager::EncryptionManager() {
	// TODO Auto-generated constructor stub

}

EncryptionManager::~EncryptionManager() {
	// TODO Auto-generated destructor stub
}

Encryption_AES* Encryption_AES::getSingle()
{
	static Encryption_AES* single;
	if(single==0)
	{
		single=new Encryption_AES();
	}
	return single;

}

unsigned char* Encryption_AES::Encryption(const unsigned char* inputStream,const unsigned char* keyStr,const unsigned char* iv)
{
	AES_KEY key;
    if(AES_set_encrypt_key(keyStr, 128,&key)<0)
    {
    	perror("encryption_key Error:");
    	return 0;
    }
    unsigned char* out=new unsigned char[32];
    AES_encrypt(inputStream, out,&key);

    return out;
}

unsigned char* Encryption_AES::Decryption(const unsigned char* inputStream,const unsigned char* keyStr,const unsigned char* iv)
{
	AES_KEY key;
    if(AES_set_decrypt_key(keyStr, 128,&key)<0)
    {
    	perror("encryption_key Error:");
    	return 0;
    }
    unsigned char* out=new unsigned char[1024];
    AES_decrypt(inputStream, out,&key);

    return out;
}
int Encryption_AES::GetCipherLength(int inputLength)
{
	int len=inputLength/AES_BLOCK_SIZE*AES_BLOCK_SIZE+AES_BLOCK_SIZE;
	return len;
}

int Encryption_AES::GetStreamLength(const unsigned char* Stream,int inputLength)
{
	int xLength=(int)(Stream[inputLength-1]);
	std::cout<<"xLength:"<<xLength<<std::endl;
	int len=inputLength-xLength;
	return len;
}

unsigned char* Encryption_AES::Encryption_CBC(const unsigned char* inputStream,int len,unsigned char* keyStr,unsigned char* iv)
{
	AES_KEY key;
    if(AES_set_encrypt_key(keyStr,128,&key)<0)
    {
    	perror("encryption_key Error:");
    	return 0;
    }
    unsigned char* out=new unsigned char[len];
    AES_cbc_encrypt(inputStream, out,len,&key,iv,AES_ENCRYPT);
    return out;
}

unsigned char* Encryption_AES::Decryption_CBC(const unsigned char* inputStream,int len,unsigned char* keyStr,unsigned char* iv)
{
	AES_KEY key;
    if(AES_set_decrypt_key(keyStr, 128,&key)<0)
    {
    	perror("encryption_key Error:");
    	return 0;
    }
    unsigned char* out=new unsigned char[len];
    AES_cbc_encrypt(inputStream, out,len,&key,iv,AES_DECRYPT);

    return out;
}

unsigned char* Encryption_AES::Encryption_ECB(const unsigned char* inputStream,const unsigned char* keyStr,unsigned char* iv)
{
	AES_KEY key;
    if(AES_set_encrypt_key(keyStr, 128,&key)<0)
    {
    	perror("encryption_key Error:");
    	return 0;
    }
    unsigned char* out=new unsigned char[1024];
    AES_ecb_encrypt(inputStream, out,&key,AES_ENCRYPT);

    return out;
}

unsigned char* Encryption_AES::Decryption_ECB(const unsigned char* inputStream,const unsigned char* keyStr,unsigned char* iv)
{
	//std::cout<<"秘钥长度："<<strlen((char*)keyStr)<<std::endl;
	//std::cout<<"矢量长度："<<strlen((char*)iv)<<std::endl;
	AES_KEY key;
    if(AES_set_decrypt_key(keyStr, 128,&key)<0)
    {
    	perror("encryption_key Error:");
    	return 0;
    }
    unsigned char* out=new unsigned char[1024];
    AES_ecb_encrypt(inputStream, out,&key,AES_DECRYPT);

    //std::cout<<out<<std::endl;
    return out;
}

} /* namespace basic */

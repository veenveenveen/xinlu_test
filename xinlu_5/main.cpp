//
//  main.cpp
//  xinlu_5
//
//  Created by 黄启明 on 2017/5/31.
//  Copyright © 2017年 黄启明. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "rsa.h"
#include "hex.h"
#include "files.h"
#include "randpool.h"

using namespace std;
using namespace CryptoPP;

//生成RSA密钥对
void GenerateRSAKey(unsigned int keyLength, const char *privFilename, const char *pubFilename, const char *seed);
//RSA加密
string RSAEncryptString(const char *pubFilename, const char *seed, const char *message);
//RSA解密
string RSADecryptString(const char *privFilename, const char *ciphertext);
//定义全局的随机数池
RandomPool &GlobalRNG();

int main(int argc, const char * argv[]) {
    
    const char *message = "hello world";
    
    cout<< "Origin Text:\t" << message << endl << endl;
    
    char priKey[128] = {0};
    char pubKey[128] = {0};
    char seed[1024]  = {0};
    
    // 生成 RSA 密钥对
    strcpy(priKey, "pri");  // 生成的私钥文件
    strcpy(pubKey, "pub");  // 生成的公钥文件
    strcpy(seed, "seed");
    GenerateRSAKey(1024, priKey, pubKey, seed);
    
    // RSA 加解密
    string encryptedText = RSAEncryptString(pubKey, seed, message); //公钥加密
    cout<<"Encrypted Text:\t"<<encryptedText<<endl<<endl;

    string decryptedText = RSADecryptString(priKey, encryptedText.c_str());//私钥解密
    cout<<"Decrypted Text:\t"<<decryptedText<<endl<<endl;
    
    return 0;
}
//生成RSA密钥对
void GenerateRSAKey(unsigned int keyLength, const char *privFilename, const char *pubFilename, const char *seed) {
    RandomPool randPool;
    randPool.Put((byte *)seed, strlen(seed));
    
    RSAES_OAEP_SHA_Decryptor priv(randPool, keyLength);
    HexEncoder privFile(new FileSink(privFilename));
    priv.DEREncode(privFile);
    privFile.MessageEnd();
    
    RSAES_OAEP_SHA_Encryptor pub(priv);
    HexEncoder pubFile(new FileSink(pubFilename));
    pub.DEREncode(pubFile);
    pubFile.MessageEnd();
}
//RSA加密
string RSAEncryptString(const char *pubFilename, const char *seed, const char *message)
{
    FileSource pubFile(pubFilename, true, new HexDecoder);
    RSAES_OAEP_SHA_Encryptor pub(pubFile);
    
    RandomPool randPool;
    randPool.Put((byte *)seed, strlen(seed));
    
    string result;
    StringSource(message, true, new PK_EncryptorFilter(randPool, pub, new HexEncoder(new StringSink(result))));
    return result;
}
//RSA解密
string RSADecryptString(const char *privFilename, const char *ciphertext) {
    FileSource privFile(privFilename, true, new HexDecoder);
    RSAES_OAEP_SHA_Decryptor priv(privFile);
    
    string result;
    StringSource(ciphertext, true, new HexDecoder(new PK_DecryptorFilter(GlobalRNG(), priv, new StringSink(result))));
    return result;
}
//定义全局的随机数池
RandomPool &GlobalRNG() {
    static RandomPool randomPool;
    return randomPool;
}

#ifndef __VIGENERE_H
#define __VIGENERE_H
#include "encryption.h"
using namespace std;

class VigenereEncrypt : public EncryptedFileWriter
{
    public:
        VigenereEncrypt(string fileName, string code) : EncryptedFileWriter(fileName), code(code) {}
        string encrypt(const string&) override;
    private:
        string code;
};

class VigenereDecrypt : public EncryptedFileReader 
{
    public:
        VigenereDecrypt(string fileName, string code) : EncryptedFileReader(fileName), code(code) {}
        string decrypt(const string&) override;
    private:
        string code;
};

#endif
#include "vigenere.h"
#include "encryption.h"
#include <cctype>

int indexPt = 0;

string VigenereEncrypt::encrypt(const string& word)
{
    string newStr, str;
    string word1 = EncryptedFileWriter::encrypt(word);
    string code1 = EncryptedFileWriter::encrypt(code);

    int i = 0;
    int ind = indexPt;
    while(i < word1.size()){
       if(isalpha(word1.at(i))){
          str = str + code1.at(ind);
          ind = ind + 1;}
       else{
          str = str + word1.at(i);}
                
       if(ind == code1.size()){
          ind = 0;}
       
       i++;
    }

    char letter;
    int x = 0;
    while(x < word1.size()){
       if(isalpha(word1.at(x))){
          letter = (word1.at(x) + str.at(x)) % 26;
          letter = letter + 'A';}
       else{
          letter = str.at(x);}   
               
       newStr.push_back(letter);
       x++;
    }

    return newStr;
}

string VigenereDecrypt::decrypt(const string& word) 
{
    string newStr, str;
    string word1 = EncryptedFileReader::decrypt(word);
    string code1 = EncryptedFileReader::decrypt(code);
       
    int i = 0;
    int ind = indexPt;
    while(i < word1.size()){
       if(isalpha(word1.at(i))){
          str = str + code1.at(ind);
          ind = ind + 1;}
       else{
          str = str + word1.at(i);}

       if(ind == code1.size()){
          ind = 0;}

       if(i == word1.size() - 1){
            indexPt = ind;}

       i++;
    }
    
    char letter;
    int k = 0;
    while(k < word1.size()){
       if(isalpha(word1.at(k))){
          letter = (word1.at(k) - str.at(k) + 26) % 26;
          letter = letter + 'a';}
       else{
          letter = str.at(k);}
          
       newStr.push_back(letter);
       k++;
    }
    
    return newStr;
}

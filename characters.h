/*
 Filename: characters.h
 Description: characters header file
 Author: John Carlo Cabanilla
 Date: 06/10/2022
 Course: Data Structures II
*/

#include <iostream>
#include <string>
#ifndef HUFFMAN_CARLOCABANILLA23_CHARACTERS_H
#define HUFFMAN_CARLOCABANILLA23_CHARACTERS_H


using namespace std;

class characters {
    string _c;
    size_t _count;
    string _code;
    characters* _left;
    characters* _right;
public:
    characters(characters* rhs);
    characters(const string& c);
    virtual ~characters();
    characters(const string& c, size_t count);
    characters(const string& c, size_t count,characters* left,characters* right );
    string ToString() const;
    string ToStringCode() const;
    virtual bool Equals(const characters& rhs)const;
    void Add();
    string GetChar()const;
    size_t GetCount() const;
    string GetCode()const;
    void SetCode(string& s);
    characters* GetLeft() const;
    characters* GetRight() const;
    void SetLeft(characters* c);
    void SetRight(characters* c);



};


#endif //HUFFMAN_CARLOCABANILLA23_CHARACTERS_H

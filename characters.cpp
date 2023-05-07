/*
 Filename: characters.cpp
 Description: characters c file
 Author: John Carlo Cabanilla
 Date: 06/10/2022
 Course: Data Structures II
*/

#include <iostream>
#include <sstream>
#include "characters.h"
using namespace std;

characters::characters(const string& c) : _c(c){
    _left = nullptr;
    _right = nullptr;
    _code = "";
    _count = 1;
}


characters::characters(const string& c, size_t count) : _c(c),_count(count){

    _left = nullptr;
    _right = nullptr;
    _code = "";
}


characters::characters(const string& c, size_t count, characters *left, characters *right) : _c(c),_count(count),_left(left), _right(right) {
    _code = "";
}


string characters::ToString() const {
    stringstream  ss;
    if(_c.length() ==  2){
        ss <<"{element: " << _c << ", frequency: "<< _count <<"}" ;
    }else{
        ss <<"{element:  " << _c <<  ", frequency: "<< _count <<"}" ;
    }


    return ss.str();
}



void characters::Add() {
    _count++;
}


bool characters::Equals(const characters &rhs) const {
    if (this == &rhs){
        return true;
    }else{
        return false;
    }
}

string characters::GetChar()  const{
    return _c;
}

size_t characters::GetCount() const{
    return _count;
}

void characters::SetCode(string &s) {
    _code = s;
}

string characters::ToStringCode() const {
    stringstream  ss;
    if(_c == "CR" || _c == "LR" ){
        ss <<"{key: " << _c << ", code: "<< _code <<"}" ;
    }else{
        ss <<"{key:  " << _c <<  ", code: "<< _code <<"}" ;
    }


    return ss.str();
}

characters::characters(characters *rhs) : _c(rhs->_c), _count(rhs->_count),_code(rhs->_code),_left(rhs->_left),_right(rhs->_right) {


}

characters *characters::GetLeft() const {
    return _left;
}

characters *characters::GetRight() const {
    return _right;
}

characters::~characters() {
    _left= nullptr;
    _right= nullptr;
    delete this;
}

void characters::SetLeft(characters *c) {
    _left = c;
}

void characters::SetRight(characters *c) {
    _right = c;
}

string characters::GetCode() const {
    return _code;
}





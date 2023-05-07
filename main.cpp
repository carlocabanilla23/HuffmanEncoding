/*
 Filename: main.cc
 Description: main of the program
 Author: John Carlo Cabanilla
 Date: 06/10/2022
 Course: Data Structures II
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "characters.h"
#include <vector>



using namespace std;


void PrintCodes(characters* root, string str,string input);
void PrintCodeAll(characters* root, string str);
void Frequency(string file);
void PrintSingleCode( string file,string input);
void EncodingTable(string file);
int Encode(const string& file,string output);

int main(int argc , char* argv[]) {
    string action = argv[1];
    string file = argv[2];

    if(action == "-frequency")
    {
        Frequency(file);
    }
    else if (action == "-single")
    {
        string c = argv[3];
        PrintSingleCode(file,c);

    }
    else if (action == "-encoding-table")
    {
        EncodingTable(file);
    }
    else if (action == "-encode")
    {
        string output = argv[3];
        int total = Encode(file,output) ;
        cout <<  total << " bytes written" <<endl;
    }

    return 0;
}
void Frequency(string file){
    vector<characters *> toVec;
    fstream f;
    f.open(file);

    if (f.is_open()) {
        string s;
        string buffer="";
        stringstream ss;
        size_t lines =0;
        while (getline(f, s)) {

            for (size_t i = 0; i < s.size(); i++) {
                string c;
                c = s[i];
                if (c == "\r"){
                    c = "LF";
                }

                int idx = -1;
                ////// Check Index

                for (size_t i = 0; i < toVec.size(); i++) {
                    if (toVec[i]->GetChar() == c) idx = i;
                }

                if (idx == -1) {
                   characters *schar = new characters(c);
                    toVec.push_back(schar);
                } else {
                    toVec[idx]->Add();
                }

            }
            lines++;
        }
        toVec.push_back(new characters("CR", lines));
    }

    //// Sort the Vector
    f.close();
    for (size_t i = 0; i < toVec.size(); i++) {
        for (size_t j = i + 1; j < toVec.size(); j++) {
            if (toVec[i]->GetCount() == toVec[j]->GetCount()) {
                if (int(toVec[i]->GetChar().at(0) < int(toVec[j]->GetChar().at(0)))) {
                    characters *temp = toVec[i];
                    toVec[i] = toVec[j];
                    toVec[j] = temp;
                }
            }
            if (toVec[i]->GetCount() < toVec[j]->GetCount()) {
                characters *temp = toVec[i];
                toVec[i] = toVec[j];
                toVec[j] = temp;
            }


        }
    }

    //// Print the the Sorted Table


    for (size_t i = 0 ; i < toVec.size() ; i++){
        cout << toVec[i]->ToString() << endl;

    }

    return;
}
void EncodingTable(string file){
    vector<characters *> toVec;
    fstream f;
    f.open(file);

    if (f.is_open()) {
        string s;
        size_t lines = 0;
        stringstream ss;
        while (getline(f, s)) {

            for (size_t i = 0; i < s.size(); i++) {
                string c;
                c = s[i];
                if (c == "\r"){
                    c = "LF";
                }



                int idx = -1;
                ////// Check Index

                for (size_t i = 0; i < toVec.size(); i++) {
                    if (toVec[i]->GetChar() == c) idx = i;
                }

                if (idx == -1) {
                    characters *schar = new characters(c);
                    toVec.push_back(schar);
                } else {
                    toVec[idx]->Add();
                }
            }
            lines++;
        }

        toVec.push_back(new characters("CR", lines));
    }

    //// Sort the Vector
    f.close();
    for (size_t i = 0; i < toVec.size(); i++) {
        for (size_t j = i + 1; j < toVec.size(); j++) {
            if (toVec[i]->GetCount() == toVec[j]->GetCount()) {
                if (int(toVec[i]->GetChar().at(0) < int(toVec[j]->GetChar().at(0)))) {
                    characters *temp = toVec[i];
                    toVec[i] = toVec[j];
                    toVec[j] = temp;
                }
            }
            if (toVec[i]->GetCount() < toVec[j]->GetCount()) {
                characters *temp = toVec[i];
                toVec[i] = toVec[j];
                toVec[j] = temp;
            }


        }
    }

    //// Create a sorted copy of the vector
    vector<characters*> toVecCopy;
    for (size_t l=0; l < toVec.size(); l++){
        toVecCopy.push_back(toVec[l]);
    }
    while (toVec.size() != 1) {
        characters *l = toVec[toVec.size() - 1];
        characters *r = toVec[toVec.size() - 2];
        toVec.pop_back();
        toVec.pop_back();
        string tempChar = l->GetChar() + r->GetChar();
        size_t tempCount = l->GetCount() + r->GetCount();
        characters *neo = new characters(tempChar, tempCount, l, r);
//            toVec.push_back(neo);



        size_t n = 0;
        while (toVec[n]->GetCount() >= neo->GetCount()) {
            n++;
        }

        toVec.insert(toVec.begin() + n, neo);



    }
    string s = "";

    PrintCodeAll(toVec[0], s) ;

    for (size_t l = 0 ; l < toVecCopy.size() ; l++){
        cout << toVecCopy[l]->ToStringCode() << endl;
    }



    return;

}
void PrintSingleCode(string file,string input){
    vector<characters *> toVec;
    fstream f;
    f.open(file);

    if (f.is_open()) {
        string s;
        size_t lines = 0;
        stringstream ss;
        while (getline(f, s)) {

            for (size_t i = 0; i < s.size(); i++) {
                string c;
                c = s[i];
                if (c == "\r"){
                    c = "LF";
                }



                int idx = -1;
                ////// Check Index

                for (size_t i = 0; i < toVec.size(); i++) {
                    if (toVec[i]->GetChar() == c) idx = i;
                }

                if (idx == -1) {
                    characters *schar = new characters(c);
                    toVec.push_back(schar);
                } else {
                    toVec[idx]->Add();
                }
            }
            lines++;
        }

        toVec.push_back(new characters("CR", lines));
    }


    //// Sort the Vector
    f.close();
    for (size_t i = 0; i < toVec.size(); i++) {
        for (size_t j = i + 1; j < toVec.size(); j++) {
            if (toVec[i]->GetCount() == toVec[j]->GetCount()) {
                if (int(toVec[i]->GetChar().at(0) < int(toVec[j]->GetChar().at(0)))) {
                    characters *temp = toVec[i];
                    toVec[i] = toVec[j];
                    toVec[j] = temp;
                }
            }
            if (toVec[i]->GetCount() < toVec[j]->GetCount()) {
                characters *temp = toVec[i];
                toVec[i] = toVec[j];
                toVec[j] = temp;
            }


        }
    }

    while (toVec.size() != 1) {
        characters *l = new characters (toVec[toVec.size() - 1]) ;
        characters *r = new characters (toVec[toVec.size() - 2] );
        toVec.pop_back();
        toVec.pop_back();
        string tempChar = l->GetChar() + r->GetChar();
        size_t tempCount = l->GetCount() + r->GetCount();
        characters *neo = new characters(tempChar, tempCount, l, r);
//            toVec.push_back(neo);



        size_t n = 0;
        while (toVec[n]->GetCount() >= neo->GetCount()) {
            n++;
        }

        toVec.insert(toVec.begin() + n, neo);



    }


    string s = "";
    PrintCodes(toVec[0], s,input) ;

//    DeleteTree(toVec[0]);


    return;

}
void PrintCodes(characters* root, string str, string input)
{
    if (root == nullptr)
        return;

    PrintCodes(root->GetLeft(), str + "1" , input);

    if (root->GetLeft() == nullptr && root->GetRight() == nullptr && root->GetChar() == input)
    {
      cout << str << endl;
    }

    PrintCodes(root->GetRight(), str + "0" , input);

}
void PrintCodeAll(characters* root, string str)
{
    if (root == nullptr)
        return;

    PrintCodeAll(root->GetLeft(), str + "1" );

    if (root->GetLeft() == nullptr && root->GetRight() == nullptr)
    {

       root->SetCode(str);
    }

    PrintCodeAll(root->GetRight(), str + "0");

}
int Encode(const string& file,const string output){
    vector<characters *> toVec;
    fstream f;
    f.open(file);
    vector<string> textcopy;
    size_t x = 0;
    if (f.is_open()) {
        string s;

        size_t lines = 0;
        stringstream ss;
        while (getline(f, s)) {

            for (size_t i = 0; i < s.size(); i++) {
                string c;
                c = s[i];
                if (c == "\r"){
                    c = "LF";
                }

                textcopy.push_back(c);

                int idx = -1;
                ////// Check Index

                for (size_t i = 0; i < toVec.size(); i++) {
                    if (toVec[i]->GetChar() == c) idx = i;
                }

                if (idx == -1) {
                    characters *schar = new characters(c);
                    toVec.push_back(schar);
                } else {
                    toVec[idx]->Add();
                }
            }
             textcopy.push_back("CR");
            lines++;
        }

        toVec.push_back(new characters("CR", lines));
    }

    //// Sort the Vector
    f.close();
    for (size_t i = 0; i < toVec.size(); i++) {
        for (size_t j = i + 1; j < toVec.size(); j++) {
            if (toVec[i]->GetCount() == toVec[j]->GetCount()) {
                if (int(toVec[i]->GetChar().at(0) < int(toVec[j]->GetChar().at(0)))) {
                    characters *temp = toVec[i];
                    toVec[i] = toVec[j];
                    toVec[j] = temp;
                }
            }
            if (toVec[i]->GetCount() < toVec[j]->GetCount()) {
                characters *temp = toVec[i];
                toVec[i] = toVec[j];
                toVec[j] = temp;
            }


        }
    }

    //// Create a sorted copy of the vector
    vector<characters*> toVecCopy;
    for (size_t l=0; l < toVec.size(); l++){
        toVecCopy.push_back(toVec[l]);
        x+= toVec[l]->GetCount();
    }
    while (toVec.size() != 1) {
        characters *l = toVec[toVec.size() - 1];
        characters *r = toVec[toVec.size() - 2];
        toVec.pop_back();
        toVec.pop_back();
        string tempChar = l->GetChar() + r->GetChar();
        size_t tempCount = l->GetCount() + r->GetCount();
        characters *neo = new characters(tempChar, tempCount, l, r);
//            toVec.push_back(neo);



        size_t n = 0;
        while (toVec[n]->GetCount() >= neo->GetCount()) {
            n++;
        }

        toVec.insert(toVec.begin() + n, neo);



    }
    string s = "";

    PrintCodeAll(toVec[0], s) ;
    ofstream  of;
    of.open(output);

//    for (size_t l = 0 ; l < toVecCopy.size() ; l++){
//
//    }

//    of << textcopy;
    for ( string ss : textcopy){

        for (size_t l = 0 ; l < toVecCopy.size() ; l++){
            if (toVecCopy[l]->GetChar() == ss){
                of << toVecCopy[l]->GetCode();
            }
        }
    }


    of.close();

    return x;
}
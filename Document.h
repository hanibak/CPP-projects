/*Hani bakbani 307958884 */
/*Hodaya Tamano 313302978*/

#ifndef _Document_h
#define _Document_h
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
//#include <boost/tokenizer.hpp>
// #include <boost/algorithm/string.hpp>


using namespace std;


class Document
{
private:
    vector<string> doc;
    int current;

public:
    Document();
    ~Document();
    void command_a();
    void command_pAll();
    void command_p();
    void command_n();
    void command_d();
    void command_i();
    void command_c();
    void command_num(string com);
    void command_text(string com);
    void command_s(string com);
    int getCurrent(){ return this->current; }
    void setCurrent(int num){ this->current=num; }
};
#endif
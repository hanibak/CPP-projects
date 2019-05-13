/*Hani bakbani 307958884 */
/*Hodaya Tamano 313302978*/

#include "Editor.h"
#include "Document.h"

using namespace std;

Editor::Editor(){
    // cout << "Editor c'tor"<<endl;
}

Editor::~Editor(){
    // cout << "Editor d'tor"<<endl;
}

void Editor::loop(){
    // cout << "in loop"<<endl;
    string com;
    while(com != "Q"){
        // cout << "enter command:" << endl;
        // cin >> com;
        getline(cin,com);
        if(com == "a") this->d.command_a();
        if(com == "%p") this->d.command_pAll();
        if(com == "p") this->d.command_p();
        if(com == "n") this->d.command_n();
        if(com == "d") this->d.command_d();
        if(com == "i") this->d.command_i();
        if(com == "c") this->d.command_c();
        
        if(com.substr(0, 2) == "s/") this->d.command_s(com);
        // cout<<"before!!!"<< temp<<endl;
        if(com.at(0) == '/') this->d.command_text(com);
        if(com=="0"||com=="1"||com=="2"||com=="3"||com=="4"||com=="5"||com=="6"||com=="7"||com=="8"||com=="9") this->d.command_num(com);
    }
// cout<<"out of loop q"<<endl;
}
// int Editor::stringToInt(string s){
//     int temp = stoi(s);
//     return temp;
// }

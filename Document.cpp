/*Hani bakbani 307958884 */
/*Hodaya Tamano 313302978*/

#include "Document.h"

Document::Document(){
    // cout << "Doc c'tor"<<endl;
    this->current=0;
}

Document::~Document(){
    // cout << "Doc d'tor"<<endl;
    doc.clear();
}

void Document::command_a(){
    if(this->current == this->doc.size()){
        string input;
        // cin >> input;
        getline(cin,input);
        while(input!= "."){
            this->doc.push_back(input);
            this->current++;
            getline(cin,input);
        }
    //    if(input==".") cout<<"dot"<<endl;
    }
    else{
        string input2;
        // cout<<"edge case, insert in the middle of the vector"<<endl; //send to command_i??
        // cin>>input2;
        getline(cin,input2);
        while(input2 != "."){
            int i=this->getCurrent();
            auto it=this->doc.insert(this->doc.begin()+i,input2);
            this->current++;
            // cin>>input2;
            getline(cin,input2);
        }  
    }
}

void Document::command_pAll(){
    // cout << "in pAll command" << endl;
    for(int i=0; i < this->doc.size(); i++){
        cout << this->doc[i] <<endl;
    }
}

void Document::command_p(){
    // cout << "in p command " << endl;
    int i = this->getCurrent()-1;
    // cout << "current is:" << this->getCurrent() << endl;
    cout << this->doc[i] <<endl;
}

void Document::command_n(){ //shows the number of current line and prints the line
    int i = this->getCurrent()-1;
    cout << i+1 << "\t" << this->doc[i] << endl;
}

void Document::command_d(){ //delete the current line
    int i = this->getCurrent()-1;
    auto it = this->doc.erase(this->doc.begin()+i);
    this->current--;   
}

void Document::command_i(){ //insert before the current
    // cout<<"the current is: "<< this->getCurrent()<<endl;
    int num =this->getCurrent()-1;
    string input;
    getline(cin, input);
    // cin >> input;
    auto it = this->doc.insert(this->doc.begin()+num, input);
    this->current++;
}

void Document::command_c(){ //change the current line for text that follow 
    int i = this->getCurrent()-1;
    auto it = this->doc.erase(this->doc.begin()+i);
    string input;
    getline(cin, input);
    // cin >> input;
    auto it2 = this->doc.insert(this->doc.begin()+i, input);
}

void Document::command_num(string com){
    // cout << "at command_num " << com <<endl;
    this->current=stoi(com);
    int i = this->getCurrent()-1;
    // cout << "the current now is " << this->getCurrent() <<endl;
    cout << this->doc[i] <<endl;
}

void Document::command_text(string com){
    bool flag=false;
    int row;
    string str = com.substr(1,com.size());
    // cout << "str is:  " << str <<endl;//

    for(int i=this->getCurrent() ; i<this->doc.size() && flag==false; i++){ //current to end
        size_t found = this->doc[i].find(str); 
        // cout<<"found is: "<< found<<endl;//
        if (found != string::npos) {
            flag=true;
            row=i;
        }
    }
    // cout<<"currenr before: "<< this->getCurrent()<<endl;//
    if (flag==true) {
        // cout<<"true"<<endl;
        this->current=row+1;
    }
    // cout<<"currenr after: "<< this->getCurrent()<<endl;//
    for(int i=0 ; i<this->getCurrent() && flag==false; i++){ //start to current
        size_t found = this->doc[i].find(str); 
        // cout<<"found is: "<< found<<endl;//
        if (found != string::npos){
            flag=true;
            row=i;
        }
    }
    // cout<<"currenr before: "<< this->getCurrent()<<endl;//
    if (flag==true){
        // cout<<"true"<<endl;
        this->current=row+1;
    }
    cout<< this->doc[this->current-1]<<endl;//
}

// void Document::command_s(string com){
//     string str=com.substr(2,com.size());
//     vector<string> result;
//     boost::split(result, str, boost::is_any_of("/"));
//     string temp =this->doc[this->getCurrent()-1];
    
//     // cout<<"old temp: "<< temp <<endl;
//     // cout<<"result[0]: "<< result[0] <<endl;
//     // cout<<"result[1]: "<< result[1] <<endl;
//     // cout<<"result[2]: "<< result[2] <<endl;

//     size_t found = temp.find(result[1]); 
//     if (found != string::npos) {
//         // cout<<"found: "<< found<<endl;
//         temp.replace(found, result[1].size(), result[2]);
//         auto it = this->doc.erase(this->doc.begin()+this->getCurrent()-1);
//         auto it2 = this->doc.insert(this->doc.begin()+this->getCurrent()-1, temp);
//         // cout<<"new temp: "<< temp <<endl;//
//     }

// }
void Document::command_s(string com){
//    cout<<"command_s"<<endl;//
    vector<string> re;
//    cout<<"com: "<< com <<endl;
    string str=com.substr(2,com.size());
//    cout<<"old str: "<< str <<endl;
    size_t found = str.find("/");
    string temp=str.substr(0,found); 
    re.push_back(temp);
    string temp2=str.substr(found+1,str.size()-found-2);
    re.push_back(temp2);
//       str.replace(found, re[0].size(), re[1]);
//       cout<<"new str: "<< str <<endl;
//       auto it = this->doc.erase(this->doc.begin()+this->getCurrent());
//        auto it2 = this->doc.insert(this->doc.begin()+this->getCurrent()-1, str);

    int i = this->getCurrent()-1;
    found = this->doc[i].find(temp);
    this->doc[i].replace(found, re[0].size(), re[1]);
    // cout << "the current now is " << this->getCurrent() <<endl;
 //   cout << this->doc[i] <<endl;
}

/*Hani bakbani 307958884 */
/*Hodaya Tamano 313302978*/

#ifndef _Editor_h
#define _Editor_h
#include <iostream>
#include "Document.h"

using namespace std;

class Editor{
    private:
        Document d;
    public:
        Editor();
        ~Editor();
        void loop();
        // stringToInt(string s);
};

#endif
//getline(cin, input)
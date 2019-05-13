#include "Document.h"
#include "Editor.h"

int main(){

    Editor ed;
    ed.loop();
    return 0;
}

/*bugs:
1) %p - prints the dot.
2) a - need to handle  the edge case (insert in the middle).
*/
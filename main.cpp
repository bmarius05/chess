#include <iostream>
#include "dependencies.h"

using namespace std;
typedef unsigned long long ull;

extern map table;

int main(){
    if(!initializeTable())
        return -1;
    showTable();
    moves nextmove;
    cin>>nextmove.sc>>nextmove.sl;
    cin>>nextmove.ec>>nextmove.el;
    if(!(nextmove.ec>='a'&&nextmove.ec<='h'&&nextmove.sc>='a'&&nextmove.sc<='h'&&nextmove.sl>=1&&nextmove.sl<=8&&nextmove.el>=1&&nextmove.el<=8))
        return -1;
    int status = makemove(nextmove);
    switch (status)
    {
    case 1:
        showTable();
        break;
    case -1:
        cout<<"Illegal Move - Capturing Own Piece at "<<nextmove.ec<<nextmove.el<<'\n';
        break;
    case -2:
        cout<<"Illegal Move - No Piece at "<<nextmove.sc<<nextmove.sl<<'\n';
        break;
    default:
        cout<<"Illegal Move"<<'\n';
        break;
    }

    cout<<"\u2713";
    
    return 0;
}
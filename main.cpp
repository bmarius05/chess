#include <iostream>
#include "dependencies.h"

using namespace std;
typedef unsigned long long ull;

extern char table[8][8];

int main(){
    system("cls");
    if(!initializeTable())
        return -1;
    showTable();
    moves nextmove;
    char c; int l;
    cout<<'\n';
    cin>>c>>l;
    nextmove.sc=c-'a';
    nextmove.sl=l-1;
    cin>>c>>l;
    nextmove.ec=c-'a';
    nextmove.el=l-1;
    if(!(nextmove.ec>=0&&nextmove.ec<8&&nextmove.sc>=0&&nextmove.sc<8&&nextmove.sl>=0&&nextmove.sl<8&&nextmove.el>=0&&nextmove.el<8))
        return -1;
    int status = makemove(nextmove);
    switch (status)
    {
    case 1:
        system("cls");
        showTable();
        break;
    case -1:
        cout<<"Illegal Move - Capturing Own Piece at "<<(char)(nextmove.ec+'a')<<nextmove.el+1<<'\n';
        break;
    case -2:
        cout<<"Illegal Move - No Piece at "<<(char)(nextmove.sc+'a')<<nextmove.sl+1<<'\n';
        break;
    default:
        cout<<"Illegal Move"<<'\n';
        break;
    }
    
    return 0;
}
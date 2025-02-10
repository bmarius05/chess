#include <iostream>
#include "dependencies.h"

using namespace std;
map table;
char pcs[][4]={"\u2659", "\u2658", "\u2657", "\u2656", "\u2655", "\u2654", 
              "\u265F", "\u265E", "\u265D", "\u265C", "\u265B", "\u265A", " "};
char pieces[]="PNBRQKpnbrqk";
int mag[]={1,3,3,5,9,100000,-1,-3,-3,-5,-9,-100000};

void showbinary(unsigned long long n, int nr, char p){
    if(nr==sizeof(n)*8)
        cout<<"  ABCDEFGH";
    if(nr==0){
        cout<<"\n  ABCDEFGH\n";
    }else{
        if(nr%8==0)
            cout<<endl<<nr/8<<' ';
        if(n%2)
            cout<<p;
        else
            cout<<'-';
        showbinary(n/2, nr-1, p);
    }
}

unsigned long long pos(int l, char c){
    return 1LL<<8*(8-l)+(c-'a');
}
short initializeTable(){
    table.pieces[0]=0;
    table.pieces[2]=pos(1,'c')+pos(1,'f'); 
    table.pieces[1]=pos(1,'b')+pos(1,'g'); 
    table.pieces[3]=pos(1,'a')+pos(1,'h'); 
    table.pieces[4]=pos(1,'d'); 
    table.pieces[5]=pos(1,'e'); 
    table.pieces[6]=0;
    table.pieces[8]=pos(8,'c')+pos(8,'f'); 
    table.pieces[7]=pos(8,'b')+pos(8,'g'); 
    table.pieces[9]=pos(8,'a')+pos(8,'h'); 
    table.pieces[10]=pos(8,'d'); 
    table.pieces[11]=pos(8,'e');
    for(char c='a';c<='h';c++){
        table.pieces[0]+=pos(2,c);
        table.pieces[6]+=pos(7,c);
    }
    return 1; 
}
int getPiece(int l, char c){
    for(int i=0;i<12;i++)
        if(table.pieces[i]&pos(l,c))
            return i;
    return 12;
}
void showTable(){
    cout<<"\n  ";
    for(char j='A';j<='H';j++)
        cout<<j<<' ';
    for(int i=8;i>=1;i--){
        cout<<'\n'<<i<<' ';
        for(char j='a';j<='h';j++){
            int p=getPiece(i, j);
            if(p<12)
                cout<<pcs[p]<<' ';
            else if((i+j)%2==0)
                cout<<"\u25A1 ";
            else
                cout<<"\u25A0 ";
        }
    }
    cout<<"\n  ";
    for(char j='A';j<='H';j++)
        cout<<j<<' ';
    cout<<'\n';
}
float valueof(ull pos, int piece){
    int val=0;
    while(pos){
        if(pos%2)
            val+=mag[piece];
        pos/=2;
    }
    return val;
}

float eval(){
    float eval=0;
    for(int i=0;i<12;i++)
        eval+=valueof(table.pieces[i], i);
    return eval;
}
int makemove(moves m){
    for(int i=0;i<12;i++){
        if(table.pieces[i]&pos(m.sl,m.sc)){
            table.pieces[i]=table.pieces[i]&(~pos(m.sl,m.sc));
            for(int j=0;j<6;j++)
                if(table.pieces[j]&pos(m.el,m.ec))
                    return -1;
            for(int j=6;j<12;j++)
                if(table.pieces[j]&pos(m.el,m.ec))
                    table.pieces[j]=table.pieces[j]&(~pos(m.el,m.ec));
            table.pieces[i]=table.pieces[i]|pos(m.el,m.ec);
            return 1;
        }
    }
    return -2;
}
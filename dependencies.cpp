#include <iostream>
#include "dependencies.h"

using namespace std;
char table[8][8];

char pcs[][4]={ " ", "\u265F", "\u265E", "\u265D", "\u265C", "\u265B", "\u265A", 
                "\u2659", "\u2658", "\u2657", "\u2656", "\u2655", "\u2654" };
char pieces[]=" PNBRQKpnbrqk";
int mag[]={0,1,3,3,5,9,100000,-1,-3,-3,-5,-9,-100000};

short initializeTable(){
    table[0][0]=table[0][7]=4;
    table[0][1]=table[0][6]=2;
    table[0][2]=table[0][5]=3;
    table[0][3]=5;
    table[0][4]=6;
    table[7][0]=table[7][7]=10;
    table[7][1]=table[7][6]=8;
    table[7][2]=table[7][5]=9;
    table[7][3]=11;
    table[7][4]=12;
    for(int i=0;i<8;i++){
        table[1][i]=1;
        table[6][i]=7;
    }
    return 1; 
}
void showTable(){
    cout<<"\n  ";
    for(char j='A';j<='H';j++)
        cout<<j<<' ';
    for(int i=7;i>=0;i--){
        cout<<'\n'<<i+1<<' ';
        for(char j=0;j<8;j++){
            if(table[i][j]>0)
                cout<<pcs[table[i][j]]<<' ';
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
float valueof(int piece){
    int val=0;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(table[i][j]==piece)
                val+=mag[piece];
    return val;
}

float eval(){
    float eval=0;
    for(int i=0;i<12;i++)
        eval+=valueof(i);
    return eval;
}
int makemove(moves m){
    if(table[m.sl][m.sc]>0){
        char p=table[m.sl][m.sc];
        table[m.sl][m.sc]=0;
        if(table[m.el][m.ec]==0||(table[m.el][m.ec]>6&&p<=6)||(table[m.el][m.ec]<=6&&p>6)){
            table[m.el][m.ec]=p;
            return 1;
        }else{
            return -1;
        }
    }
    return -2;
}
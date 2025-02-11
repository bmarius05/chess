#ifndef DEPENDENCIES_H
#define DEPENDENCIES_H

extern char table[8][8];
struct moves{
  int sl, el;
  int sc, ec;  
};

void showbinary(unsigned long long n, int nr, char p);
unsigned long long pos(int l, char c);
void showTable();
short initializeTable();
float eval();
int makemove(moves m);


#endif
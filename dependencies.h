#ifndef DEPENDENCIES_H
#define DEPENDENCIES_H
typedef unsigned long long ull;
struct map{
    ull pieces[12];
};

struct moves{
  int sl, el;
  char sc, ec;  
};
extern map table;

void showbinary(unsigned long long n, int nr, char p);
unsigned long long pos(int l, char c);
void showTable();
short initializeTable();
float eval();
int makemove(moves m);


#endif
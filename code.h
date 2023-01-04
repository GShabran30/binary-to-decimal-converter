#ifndef CODE_H_INCLUDED
#define CODE_H_INCLUDED

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define top(S) ((S).top)
#define bottom(S) ((S).bottom)
#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info

typedef struct ElmStack *adr;

struct ElmStack {
    string info;
    adr next ;
    adr prev ;
};

struct Stack{
    adr top,bottom;
};

Stack creatStack();
adr newElm(int INP);
bool isEmpty(Stack S);
void push(Stack &S, adr p);
string twoNdComplement(string bin1,string bin2);
int getIntValue();
string getBiner();
Stack Des2Bin(int INP);
int Bin2Des(string INP);
void ShowBinary(Stack INP);
int menu();

#endif // CODE_H_INCLUDED

#include "code.h"

Stack creatStack(){
    Stack S;
    top(S) = NULL;
    bottom(S) = NULL;
    return S;
};
adr newElm(int INP){
    adr p = new ElmStack;

    info(p) = INP;
    next(p) = NULL;
    prev(p) = NULL;

    return p;
};
bool isEmpty(Stack S){
    if (top(S) == NULL && bottom(S) == NULL){
        return true;
    }else{
        return false;
    }
};
void push(Stack &S, adr p){
    if (top(S) == NULL && bottom(S) == NULL){
        top(S) = p;
        bottom(S) = p;
    }else{
        next(p) = top(S);
        prev(top(S)) = p;
        top(S) = p;
    }
};
int getIntValue(){
    int INP;
    cout << "Input Bilangan Bulat : ";
    cin >> INP;
    return INP;
};
string getBiner(){
    int INP;
    cout << "Input Biner String : ";
    cin >> INP;
    return to_string(INP);
};
string twoNdComplement(string bin1){
    string bin2, hasil;
    int carry, re, i;

    int len = bin1.size();

    for(i=(len-2); i>-1; i--){
        bin2.append("0");
    }
    bin2.append("1");

    hasil = "";
    carry = 0;

    for(i=(len-1); i>-1; i--){
        re = carry;
        if(bin1[i] == '1')
            re = re+1;
        else
            re = re+0;
        if(bin2[i] == '1')
            re = re+1;
        else
            re = re+0;
        if(re%2==1)
            hasil = '1' + hasil;
        else
            hasil = '0' + hasil;
        if(re<2)
            carry = 0;
        else
            carry = 1;
    }
    if(carry!=0){
        hasil = '1' + hasil;
    }
    return hasil;
};
Stack Des2Bin(int INP){
    Stack S = creatStack();

    int input = INP;
    if (INP < 0){
        input = -INP;
    }

    string temp;
    string positive;
    string negative;

    while(input > 0){
        temp.append(to_string(input % 2));
        input /= 2;
    }

    int a;
    int lenTemp = temp.size();
    for(a=(lenTemp-1); a>-1; a--){
        positive += temp[a];
        if(INP >= 0 ){
            push(S,newElm(temp[a]));
        }
        if(temp[a] == '0'){
            negative += '1';
        }else{
            negative += '0';
        }
    }

    string hasil = twoNdComplement(negative);
    int i;
    int lenHasil = hasil.size();
    if (INP < 0){
        for (i = -1 ; i <(lenHasil) ; i++){
        push(S,newElm(hasil[i]));
        }
    }
    cout<<"Isi Stack : ";
    ShowBinary(S);
    cout<<endl;


    return S;
};
int Bin2Des(string INP){
    Stack S = creatStack();

    int i,N,decimalNumber=0,p=0;
    N=INP.size();
    for(i=N-1;i>=0;i--)
    {
        push(S,newElm(INP[i]));
        if(INP[i]=='1'){
            decimalNumber+=pow(2,p);
        }
        p++;
    }
    cout<<"Isi Stack : ";
    ShowBinary(S);
    cout<<endl;

    return decimalNumber;
};
void ShowBinary(Stack INP){
    adr cur = bottom(INP);
    while(cur != NULL){
        cout<<info(cur);
        cur = prev(cur);
    }
};
int menu(){
    int input;
    cout << "MENU" <<endl;
    cout<< "1. Decimal To Binary"<<endl;
    cout<< "2. Binary To Decimal"<<endl;
    cout<< "3. Selesai"<<endl;
    cout<<endl;

    cout <<"Pilih Menu : ";
    cin >>input;
    cout<<endl;

    return input;
};

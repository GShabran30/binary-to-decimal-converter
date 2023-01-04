#include "code.h"

using namespace std;


int main()
{
    int pilihan = menu();
    while(pilihan != 3){

        if (pilihan == 1){
            int intDesimal = getIntValue();
            Stack S = Des2Bin(intDesimal);
            cout<<"Biner dari "<<intDesimal<<" adalah : ";
            ShowBinary(S);
            cout<<endl;
            cout<<endl;
        }else if(pilihan == 2){
            string strBiner = getBiner();
            int desimal = Bin2Des(strBiner);
            cout<<"Desimal dari biner "<<strBiner<<" adalah : "<<desimal<<endl;
            cout<<endl;
        }else {
            cout<<"Input Pilihan salah, Silahkan input ulang.."<<endl;
            cout<<endl;
        }
        pilihan = menu();
    }

    cout<<"Terimakasih, anda telah keluar dari program..."<<endl;


}

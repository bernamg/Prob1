#include <iostream>
using namespace std;

struct board{
    int numero;
    int jaMexeu;
};

int swipeRight(struct board *b, int pos){ // começa na direita -> pos=col
    if(pos==0) // ja nao tem elementos para juntar com
        return b[pos].numero;

    if(b[pos].numero == swipeRight(b,pos-1)){
        if(b[pos].jaMexeu==0){
            b[pos].numero *=2;
            b[pos-1].numero =0;
            b[pos].jaMexeu=1;
            b[pos-1].jaMexeu=1;
        }
    }

    return b[pos].numero;
}

int main(){
    // Assumir que nao ha 0
    struct board b[3];
    b[0].numero = 2;
    b[1].numero = 2;
    b[2].numero = 4;

    int col=3;
    swipeRight(b,col);
    for(int i=0;i<col;i++)
        cout << b[i].numero << "\n";

    cout << "Isto e um teste";
    return 0;
}
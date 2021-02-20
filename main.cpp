#include <iostream>
#include <vector>
using namespace std;


class Tile{
public:
    int numero;
    int jaMexeu;
};

//TODO: Criar mecanicas e algoritmo, por essa funcao na linha 36 e ver onde guardar resultados

int DataReceive(){
    int testNumber, sizeBoard, slides;
    vector<Tile> gameBoard;
    Tile numTile;
    cin >> testNumber;                      //Numero de testes a efetuar
    for (int i=0;i<testNumber;i++){
        cin >> sizeBoard;
        cin >> slides;
        for (int j=0;j<sizeBoard*sizeBoard;j++){
            cin >> numTile.numero;
            gameBoard.push_back(numTile);
        }
        for (Tile T : gameBoard){
            cout << T.numero << " ";
        }
        //Mecanicas e algoritmo
        cout << "\n";
        gameBoard.clear();
    }
    return 1;
}



/*int swipeRight(struct board *b, int pos){ // começa na direita -> pos=col
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
}*/



int main(){
    DataReceive();
    /*
    // Assumir que nao ha 0
    struct board b[3];
    b[0].numero = 2;
    b[1].numero = 2;
    b[2].numero = 4;
    int col=3;
    swipeRight(b,col);
    for(int i=0;i<col;i++)
        cout << b[i].numero << "\n";
*/
    return 0;
}
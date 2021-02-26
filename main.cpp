#include <iostream>
#include <vector>
using namespace std;


class Tile{
public:
    int numero;
    int jaMexeu;
};

//TODO: Criar mecanicas e algoritmo, por essa funcao na linha 31 e ver onde guardar resultados

int SlideRight(int offset, int slides,vector<int> &gameBoard){
    int changes = offset;
    slides --;
    for (int j =0; j<changes;j++) {
        for (int i = offset - 1; i >= 0; i--) {
            for (int k = i - 1; k >= offset - changes; k--) {
                //cout << "Valor de i:" <<gameBoard[i] << "\t" << gameBoard[k] << "\n";
                if (gameBoard[i] == 0 && gameBoard[k] != 0) {
                    gameBoard[i] = gameBoard[k];
                    gameBoard[k] = 0;
                }
                else if (gameBoard[i] != 0 && gameBoard[i] == gameBoard[k]) {
                    // cout << gameBoard[i]<< "\t" << gameBoard[k] << "\n";
                    // cout << "Entrei aqui" << "\n";
                    gameBoard[i] = gameBoard[i] * 2;
                    gameBoard[k] = 0;
                }
                else if(gameBoard[k] != 0){
                    break;
                }
            }
        }
        /*for (int i : gameBoard){
            cout << i << " ";
        }
        cout << "\n";*/
        offset = offset + changes;
    }
    return slides;
}

int SlideLeft(int offset, int slides,vector<int> &gameBoard){
    int changes = offset;
    slides --;
    for (int j =0; j<changes;j++) {
        for (int i = 0; i < offset; i++) {
            for (int k = i + 1; k < offset + changes; k++) {
                //cout << "Valor de i:" <<gameBoard[i] << "\t" << gameBoard[k] << "\n";
                if (gameBoard[i] == 0 && gameBoard[k] != 0) {
                    gameBoard[i] = gameBoard[k];
                    gameBoard[k] = 0;
                }
                else if (gameBoard[i] != 0 && gameBoard[i] == gameBoard[k]) {
                    // cout << gameBoard[i]<< "\t" << gameBoard[k] << "\n";
                    // cout << "Entrei aqui" << "\n";
                    gameBoard[i] = gameBoard[i] * 2;
                    gameBoard[k] = 0;
                }
                else if(gameBoard[k] != 0){
                    break;
                }
            }
        }
        for (int i : gameBoard){
            cout << i << " ";
        }
        cout << "\n";
        offset = offset + changes;
    }
    return slides;
}

int DataReceive(){
    int testNumber, sizeBoard, slides, num;
    vector<int> gameBoard;
    cin >> testNumber;                      //Numero de testes a efetuar


    for (int i=0;i<testNumber;i++){
        cin >> sizeBoard;
        cin >> slides;
        for (int j=0;j<sizeBoard*sizeBoard;j++){
            cin >> num;
            gameBoard.push_back(num);
        }
        //------------------------Print----------------------
        for (int i : gameBoard){
            cout << i << " ";
        }
        //---------------------------------------------------
        //Mecanicas e algoritmo
        cout << "\n";
        slides = SlideLeft(sizeBoard,slides,gameBoard);

        gameBoard.clear();
        break;
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
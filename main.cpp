#include <iostream>
#include <vector>
using namespace std;


//TODO: Remvoer prints dos slides e algoritmo

void SlideRight(int offset,vector<int> &gameBoard){
    int changes = offset;
    for (int j =0; j<changes;j++) {
        for (int i = offset - 1; i >= offset - changes; i--) {
            for (int k = i - 1; k >= offset - changes; k--) {
                if (gameBoard[i] == 0 && gameBoard[k] != 0) {
                    gameBoard[i] = gameBoard[k];
                    gameBoard[k] = 0;
                }
                else if (gameBoard[i] != 0 && gameBoard[i] == gameBoard[k]) {
                    gameBoard[i] = gameBoard[i] * 2;
                    gameBoard[k] = 0;
                    break;
                }
                else if(gameBoard[k] != 0){
                    break;
                }
            }
        }
       /* for (int i : gameBoard){
            cout << i << " ";
        }
        cout << "\n";*/
        offset = offset + changes;
    }
}


void SlideLeft(int offset,vector<int> &gameBoard){
    int changes = offset;
    for (int j =0; j<changes;j++) {
        for (int i = offset- changes; i < offset; i++) {
            for (int k = i + 1; k < offset; k++) {
                if (gameBoard[i] == 0 && gameBoard[k] != 0) {
                    gameBoard[i] = gameBoard[k];
                    gameBoard[k] = 0;
                }
                else if (gameBoard[i] != 0 && gameBoard[i] == gameBoard[k]) {
                    gameBoard[i] = gameBoard[i] * 2;
                    gameBoard[k] = 0;
                    break;
                }
                else if(gameBoard[k] != 0){
                    break;
                }
            }
        }
       /* for (int i : gameBoard){
            cout << i << " ";
        }
        cout << "\n";*/
        offset = offset + changes;
    }
}

void SlideDown(int offset,vector<int> &gameBoard){
    int changes = offset, salto = offset;
    int firstPos = (offset*offset) - offset;

    for (int j =0; j<changes;j++) {
        for (int i = firstPos + j; i >= 0; i-=salto) {
            for (int k = i - salto; k >= 0; k-=salto) {
                 if (gameBoard[i] == 0 && gameBoard[k] != 0) {
                     gameBoard[i] = gameBoard[k];
                     gameBoard[k] = 0;
                 }
                 else if (gameBoard[i] != 0 && gameBoard[i] == gameBoard[k]) {
                     gameBoard[i] = gameBoard[i] * 2;
                     gameBoard[k] = 0;
                     break;
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
}

void SlideUp(int offset,vector<int> &gameBoard){
    int changes = offset, salto = offset;
    int lastPos = offset * offset;
    for (int j =0; j<changes;j++) {
        for (int i = j; i < lastPos; i+= salto) {
            for (int k = i + salto; k < lastPos; k+=salto) {
                if (gameBoard[i] == 0 && gameBoard[k] != 0) {
                    gameBoard[i] = gameBoard[k];
                    gameBoard[k] = 0;
                }
                else if (gameBoard[i] != 0 && gameBoard[i] == gameBoard[k]) {
                    gameBoard[i] = gameBoard[i] * 2;
                    gameBoard[k] = 0;
                    break;
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
      /*  for (int i : gameBoard){
            cout << i << " ";
        }*/
        //---------------------------------------------------
        //Mecanicas e algoritmo
        cout << "\n";
        SlideUp(sizeBoard,gameBoard);

        gameBoard.clear();
        cout << "\n\n";

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
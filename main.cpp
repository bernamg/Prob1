#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxSlides, sizeBoard, win;
vector<int> prevBoard;
void SlideUpRec(vector<int> &gameBoard, int nSlides);
void SlideLeftRec(vector<int> &gameBoard, int nSlides);
void SlideRightRec(vector<int> &gameBoard, int nSlides);
void SlideDownRec(vector<int> &gameBoard, int nSlides);

//TODO: Remover prints dos slides e algoritmo

/*bool checkNumerosIguais(vector<int> &b1){
    int i,n=sizeBoard*sizeBoard;
    for(i=0;i<n;i++) {
        if (b1[i] > 0) {
            if (count(b1.begin(), b1.end(), b1[i]) > 1) {
                return true;
            }a
        }
    }
    return false;
}*/


int countPieces(vector<int> &b1){
    int i,n=sizeBoard*sizeBoard,np=0;
    for(i=0;i<n;i++){
        if(b1[i]>0)
            np++;
    }
    return np;
}

bool checkEqualBoards(vector<int> &b1, vector<int> &b2){
    int i,n=sizeBoard*sizeBoard;
    for(i=0;i<n;i++)
        if(b1[i]!=b2[i])
            return false;
    return true;
}

void printGameBoard(vector<int> &gameBoard){
    cout << "Print GameBoard\n";
    for (int i : gameBoard){
        cout << i << " ";
    }

    cout << "\nEnd of Print GameBoard\n\n";
}
void SlideRight(vector<int> &gameBoard){
    int offset = sizeBoard;
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
        /*  for (int i : gameBoard){
              cout << i << " ";
          }
          cout << "\n";*/
        offset = offset + changes;
    }
}

void SlideLeft(vector<int> &gameBoard){
    int offset = sizeBoard;
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
        offset = offset + changes;
    }
}


void SlideDown(vector<int> &gameBoard){
    int offset = sizeBoard;
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
        offset = offset + changes;
    }
}

void SlideUp(vector<int> &gameBoard){
    int offset = sizeBoard;
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
        offset = offset + changes;
    }
}

bool CheckWin(vector<int> &gameBoard){
    int contador = 0;
    int n=gameBoard.size();
    for(int i =0;i<n;i++){
        if (gameBoard[i]!=0){
            contador++;
        }
    }
    if (contador==1){
        return true;
    }else{
        return false;
    }
}


void SlideLeftRec(vector<int> &gameBoard, int nSlides){
    if (CheckWin(gameBoard)){
        win = nSlides;
        return;
    }
    if (nSlides >= maxSlides || (win <= nSlides && win>0)){
        return;
    }
    /*if(nSlides > countPieces(gameBoard)){
        return;
    }*/
    prevBoard = gameBoard;
    SlideLeft(gameBoard);
    if(checkEqualBoards(prevBoard, gameBoard)) {
        return;
    }
    nSlides++;
    //----------------------------------------------------------------------------
    //vector<int> gameBoardR = gameBoard;
    vector<int> gameBoardL = gameBoard;
    vector<int> gameBoardU = gameBoard;
    vector<int> gameBoardD = gameBoard;

    SlideDownRec(gameBoardL, nSlides);
    // SlideRightRec(gameBoardR, nSlides);
    SlideUpRec(gameBoardU, nSlides);
    SlideLeftRec(gameBoardD, nSlides);

}

void SlideDownRec(vector<int> &gameBoard, int nSlides){
    if (CheckWin(gameBoard)){
        win = nSlides;
        return;
    }
    if (nSlides >= maxSlides || (win <= nSlides && win>0)){
        return;
    }

    prevBoard = gameBoard;
    SlideDown(gameBoard);
    if(checkEqualBoards(prevBoard, gameBoard)) {
        return;
    }
    nSlides++;
    //----------------------------------------------------------------------------
    vector<int> gameBoardR = gameBoard;
    vector<int> gameBoardL = gameBoard;
    //vector<int> gameBoardU = gameBoard;
    vector<int> gameBoardD = gameBoard;

    SlideRightRec(gameBoardR, nSlides);
    // SlideUpRec(gameBoardU, nSlides);
    SlideLeftRec(gameBoardD, nSlides);
    SlideDownRec(gameBoardL, nSlides);
}


void SlideUpRec(vector<int> &gameBoard, int nSlides){

    if (CheckWin(gameBoard)){
        win = nSlides;
        return;
    }
    if (nSlides >= maxSlides || (win <= nSlides && win>0)){
        return;
    }

    prevBoard = gameBoard;
    SlideUp(gameBoard);
    if(checkEqualBoards(prevBoard, gameBoard)) {
        return;
    }
    nSlides++;
    //----------------------------------------------------------------------------
    vector<int> gameBoardR = gameBoard;
    // vector<int> gameBoardL = gameBoard;
    vector<int> gameBoardU = gameBoard;
    vector<int> gameBoardD = gameBoard;
    // SlideDownRec(gameBoardL, nSlides);
    SlideRightRec(gameBoardR, nSlides);
    SlideLeftRec(gameBoardD, nSlides);
    SlideUpRec(gameBoardU, nSlides);
}

void SlideRightRec(vector<int> &gameBoard, int nSlides){
    if (CheckWin(gameBoard)){
        win = nSlides;
        return;
    }
    if (nSlides >= maxSlides || (win <= nSlides && win>0)){
        return;
    }

    prevBoard = gameBoard;
    SlideRight(gameBoard);
    if(checkEqualBoards(prevBoard, gameBoard)) {
        return;
    }
    nSlides++;
    //----------------------------------------------------------------------------
    vector<int> gameBoardR = gameBoard;
    vector<int> gameBoardL = gameBoard;
    vector<int> gameBoardU = gameBoard;
    //vector<int> gameBoardD = gameBoard;
    SlideDownRec(gameBoardL, nSlides);
    SlideUpRec(gameBoardU, nSlides);
    // SlideLeftRec(gameBoardD, nSlides);
    SlideRightRec(gameBoardR, nSlides);

}

void BeginAlgoritmo(vector<int> &gameBoard){
    vector<int> gameBoardR = gameBoard;
    vector<int> gameBoardL = gameBoard;
    vector<int> gameBoardU = gameBoard;
    vector<int> gameBoardD = gameBoard;
    int nslides = 0;
    SlideRightRec(gameBoardR, nslides);
    SlideDownRec(gameBoardL, nslides);
    SlideUpRec(gameBoardU, nslides);
    SlideLeftRec(gameBoardD, nslides);


}


int DataReceive(){
    int testNumber, num;
    vector<int> gameBoard;
    cin >> testNumber;                      //Numero de testes a efetuar


    for (int i=0;i<testNumber;i++){
        cin >> sizeBoard;
        cin >> maxSlides;
        for (int j=0;j<sizeBoard*sizeBoard;j++){
            cin >> num;
            gameBoard.push_back(num);
        }
        //------------------------Print----------------------
        /*cout << "Board Inicial\n";
        for (int i : gameBoard){
            cout << i << " ";
        }
        cout << "\n\n";*/
        //---------------------------------------------------
        //Mecanicas e algoritmo
        BeginAlgoritmo(gameBoard);
        if ( win <=0){
            cout << "no solution\n";
        }
        else{
            cout << win << "\n";
        }

        /* cout << "print final\n";
         for (int i : gameBoard) {
             cout << i << " ";
         }
         cout << "\n";*/
        gameBoard.clear();
        win = -1;

    }
    return 1;
}



int main(){
    DataReceive();
    return 0;
}
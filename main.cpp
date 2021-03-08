#include <iostream>
#include <vector>
using namespace std;
int maxSlides, sizeBoard;

//TODO: Remover prints dos slides e algoritmo

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
       /*for (int i : gameBoard){
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
        for (int i : gameBoard){
            cout << i << " ";
        }
        cout << "\n";
        offset = offset + changes;
    }
}

/*void Carneiro(int sizeBoard, vector<int> &gameBoard) {
    //cleanup zeros
    int i, zero_pos = 0, tmp;
    int lastpos = sizeBoard * sizeBoard;
    //contar numero de zeros

    while (gameBoard[zero_pos] == 0 && zero_pos < sizeBoard) {
        zero_pos++;
    }
   // cout << zero_pos << "\n";

    for (i = sizeBoard-1; i > 0; i--) {
        if (gameBoard[i] == 0) {
            cout << "ze: " << gameBoard[zero_pos] << "\n";
            cout << "gameboard[i]:" << gameBoard[i] << "\n";
            tmp = gameBoard[zero_pos];
            gameBoard[zero_pos] = 0;
            gameBoard[i] = tmp;
            zero_pos++;
        }
    }
    cout << "Linha 82\n";
    for (int i : gameBoard) {
        cout << i << " ";
    }
    cout << "\n";

    i = sizeBoard - 1;
    while (i > 0) {
        if (gameBoard[i] == gameBoard[i - 1]) {
            gameBoard[i] = 2;
            gameBoard[i - 1] = 0;
            i -= 2;
        } else {
            i--;
        }
    }
    cout << "Linha 98\n";
    for (int i : gameBoard) {
        cout << i << " ";
    }
    cout << "\n";
    zero_pos = 0;
    while (gameBoard[zero_pos] == 0 && zero_pos < sizeBoard)
        zero_pos++;

    for (i = sizeBoard - 1; i >= 0; i--) {
        if (gameBoard[i] == 0) {
            tmp = gameBoard[zero_pos];
            gameBoard[zero_pos] = 0;
            gameBoard[i] = tmp;
        }
    }

    cout << "Depois de limpar 0\n";
    for (int i : gameBoard) {
        cout << i << " ";
    }
    cout << "\n";
}*/

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

bool CheckWin(vector<int> &gameBoard){
    int contador =0;
    for(int i =0;i<gameBoard.size();i++){
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

int Algoritmo(vector<int> &gameBoard, int nSlides, int sizeBoard){
    if (CheckWin(gameBoard)){
        return 1;
    }
    if (nSlides > maxSlides){
        return 0;
    }
    SlideRight(sizeBoard,gameBoard);

}


int DataReceive(){
    int testNumber, offset, slides, num;
    vector<int> gameBoard;
    cin >> testNumber;                      //Numero de testes a efetuar


    for (int i=0;i<testNumber;i++){
        cin >> offset;
        cin >> maxSlides;
        for (int j=0;j<offset*offset;j++){
            cin >> num;
            gameBoard.push_back(num);
        }
        //------------------------Print----------------------
        cout << "Board Inicial\n";
        for (int i : gameBoard){
            cout << i << " ";
        }
        //---------------------------------------------------
        //Mecanicas e algoritmo

        SlideRight(offset,gameBoard);

        cout << "print final\n";
        for (int i : gameBoard) {
            cout << i << " ";
        }
        cout << "\n";
        break;
        gameBoard.clear();
        cout << "\n\n";

    }
    return 1;
}







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
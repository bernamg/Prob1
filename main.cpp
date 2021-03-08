#include <iostream>
#include <vector>
using namespace std;
int maxSlides, sizeBoard, win;
int SlideUpRec(vector<int> &gameBoard, int nSlides);
int SlideLeftRec(vector<int> &gameBoard, int nSlides);
int SlideRightRec(vector<int> &gameBoard, int nSlides);
int SlideDownRec(vector<int> &gameBoard, int nSlides);

//TODO: Remover prints dos slides e algoritmo

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


int SlideLeftRec(vector<int> &gameBoard, int nSlides){
    if (CheckWin(gameBoard)){
        win = nSlides;
        return nSlides;
    }
    if (nSlides >= maxSlides){
        return -1;
    }
    SlideLeft(gameBoard);
    nSlides++;
    //----------------------------------------------------------------------------
    vector<int> gameBoardR = gameBoard;
    vector<int> gameBoardL = gameBoard;
    vector<int> gameBoardU = gameBoard;
    vector<int> gameBoardD = gameBoard;
    int res;
    if(res = SlideRightRec(gameBoardR, nSlides)>=0) return res;
    if(res = SlideDownRec(gameBoardL, nSlides)>=0) return res;
    if(res = SlideUpRec(gameBoardU, nSlides)>=0) return res;
    if(res = SlideLeftRec(gameBoardD, nSlides)>=0) return res;

    return -1;
}

int SlideDownRec(vector<int> &gameBoard, int nSlides){
    if (CheckWin(gameBoard)){
        win = nSlides;
        return nSlides;
    }
    if (nSlides >= maxSlides){
        return -1;
    }
    SlideDown(gameBoard);
    nSlides++;
    //----------------------------------------------------------------------------
    vector<int> gameBoardR = gameBoard;
    vector<int> gameBoardL = gameBoard;
    vector<int> gameBoardU = gameBoard;
    vector<int> gameBoardD = gameBoard;
    int res;
    if(res = SlideRightRec(gameBoardR, nSlides)>=0) return res;
    if(res = SlideDownRec(gameBoardL, nSlides)>=0) return res;
    if(res = SlideUpRec(gameBoardU, nSlides)>=0) return res;
    if(res = SlideLeftRec(gameBoardD, nSlides)>=0) return res;

    return -1;
}


int SlideUpRec(vector<int> &gameBoard, int nSlides){
    if (CheckWin(gameBoard)){
        win = nSlides;
        return nSlides;
    }
    if (nSlides >= maxSlides){
        return -1;
    }
    SlideUp(gameBoard);
    nSlides++;
    //----------------------------------------------------------------------------
    vector<int> gameBoardR = gameBoard;
    vector<int> gameBoardL = gameBoard;
    vector<int> gameBoardU = gameBoard;
    vector<int> gameBoardD = gameBoard;
    int res;
    if(res = SlideRightRec(gameBoardR, nSlides)>=0) return res;
    if(res = SlideDownRec(gameBoardL, nSlides)>=0) return res;
    if(res = SlideUpRec(gameBoardU, nSlides)>=0) return res;
    if(res = SlideLeftRec(gameBoardD, nSlides)>=0) return res;

    return -1;
}

int SlideRightRec(vector<int> &gameBoard, int nSlides){
    if (CheckWin(gameBoard)){
        win = nSlides;
        return nSlides;
    }
    if (nSlides >= maxSlides){
        return -1;
    }
    SlideRight(gameBoard);

    nSlides++;
    //----------------------------------------------------------------------------
    vector<int> gameBoardR = gameBoard;
    vector<int> gameBoardL = gameBoard;
    vector<int> gameBoardU = gameBoard;
    vector<int> gameBoardD = gameBoard;
    int res;
    if(res = SlideRightRec(gameBoardR, nSlides)>=0) return res;
    if(res = SlideDownRec(gameBoardL, nSlides)>=0) return res;
    if(res = SlideUpRec(gameBoardU, nSlides)>=0) return res;
    if(res = SlideLeftRec(gameBoardD, nSlides)>=0) return res;

    return -1;
}

int BeginAlgoritmo(vector<int> &gameBoard){
    vector<int> gameBoardR = gameBoard;
    vector<int> gameBoardL = gameBoard;
    vector<int> gameBoardU = gameBoard;
    vector<int> gameBoardD = gameBoard;
    int nslides = 0, res;
    if(res=SlideRightRec(gameBoardR, nslides)>=0) return res;
    if(res=SlideDownRec(gameBoardD,nslides)>=0) return res;
    if(res=SlideLeftRec(gameBoardL, nslides)>=0) return res;
    if(res=SlideUpRec(gameBoardU, nslides)>=0) return res;

    return -1;
}


int DataReceive(){
    int testNumber, slides, num, res;
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
        res = BeginAlgoritmo(gameBoard);
        if ( res ==-1){
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

    }
    return 1;
}



int main(){
    DataReceive();
    return 0;
}
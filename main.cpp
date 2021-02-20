#include <iostream>
#include <vector>
#include <list>
using namespace std;

//Number of test cases.

class Tile{
public:
    int numero;
    int jaMexeu;
};

class TestCase{
public:
    int sizeBoard;
    int slides;
    vector<Tile> gameBoard();
};

list<TestCase> DataReceive(list<TestCase> &input){          //& comercial
    TestCase newTest;
    int testNumber, sizeBoard, slides;
    Tile numTile;
    cin >> testNumber; //Numero de testes a efetuar
    for (int i=0;i<testNumber;i++){
        cin >> newTest.sizeBoard;
        cin >> newTest.slides;
        for (int j=0;j<newTest.sizeBoard*newTest.sizeBoard;j++){
            cin >> numTile.numero;
            newTest.gameBoard().push_back(numTile);
        }
        input.push_back(newTest);
    }
    return input;
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
    //Lista de Inputs
    list<TestCase> input;
    DataReceive(input);
    auto L = input.begin();
    /*for (auto const& i: input) {
        cout << "sizeBoard " <<  i.sizeBoard;
        cout << "slides " <<  i.slides << "\n";

    }*/

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
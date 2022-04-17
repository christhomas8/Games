#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

//Game size initializer
int gridSize(){
    //Select game size
    cout << "What size should the game be?" << endl;
    int gameSize;
    cin >> gameSize;
    if (gameSize > 9){
        gameSize = 9;
        cout << "Maximum size of 9 selected" << endl;
    };
    if (gameSize < 4){
        gameSize = 4;
        cout << "Minimum size of 4 selected" << endl;
    };
    
    return gameSize;
}


//Select row
int rowF(int mapSize) {
    int row;
    cout << "Select row: ";   
    cin >>  row;

    if (row > 0 && row <= mapSize){
        return row;
    }
    else{
        cout << "Selected row out of map range! \n";
        return rowF(mapSize);
    } 

    return 0;
}

//Select column
int columnF(int mapSize) {
    int column;
    cout << "Select column: ";   
    cin >>  column;
    cin.clear();

    if (column > 0 && column <= mapSize){
        return column;
    }
    else{
        cout << "Selected column out of map range! \n";
        return columnF(mapSize);
    }
    
    return 0;
}


int main(){
    const int mapSize = gridSize();
    cout << "\nGame size of " << mapSize << " selected \n" << endl;

    string arr[mapSize][mapSize];

    for (int i = 0; i < mapSize; i++) {
        
        for (int j = 0; j < mapSize; j++) {
            arr[i][j] = "*";
        }
    };

    for (int i = 0; i < mapSize ; i++) {
        cout << i+1 << "|  ";
        for (int j = 0; j < mapSize ; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << "|" << endl;
    }

    cout << "    ";

    for (int i = 0; i < mapSize; i++){
        cout << i+1 << "  ";
    }
    cout << "\n\n";
    
    //game loop
    int k = 0;
    int end = mapSize * mapSize;
    cout << "Number of Shots Available: " << end << endl;
    while (k < end){

        cout << "------------------------\n\n";

        int row =  rowF(mapSize);
        int column = columnF(mapSize);

        arr[row-1][column-1] = "X";


        //Redraw board
        for (int i = 0; i < mapSize ; i++) {
            cout << i+1 << "|  ";

            for (int j = 0; j < mapSize ; j++) {
                cout << arr[i][j] << "  ";
            }

            cout << "|" << endl;
        }
            cout << "    ";

        for (int i = 0; i < mapSize; i++){
            cout << i+1 << "  ";
        }
        cout << "\n\n";

        k++;
    }

    cout << "Game Over" << endl;
    
    return 0;
}

/*
Still Needs:
    1) History of moves
    2) Ship placement
    3) Random CPU Opponent placement
    4) Ship hit vs Missed shot function
    5) Numerical input filter
*/

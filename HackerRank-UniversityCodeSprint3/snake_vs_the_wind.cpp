#include <bits/stdc++.h>

using namespace std;

void printBoard(vector<vector<int> > board, int row, int column){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            cout << board[i][j] << " ";
        };
        cout << endl;
    };
};

bool isNorthValid(int size, int x, int y){
    return x-1 >= 0;
};
bool isSouthValid(int size, int x, int y){
    return x+1 < size;
};
bool isEastValid(int size, int x, int y){
    return y+1 < size;
}
bool isWestValid(int size, int x, int y){
    return y-1 >= 0;
}

void transverseBoard(vector<vector<int> > board, int size, int x, int y, char d){
    int count = board[x][y];
    int next = count + 1;

    // cout << x << " and " << y << endl;
    // cout << "count is : " << count << endl;
    if (count == size*size){
        printBoard(board, size, size);
    }

    switch(d){
        case 'n': {
            if (isNorthValid(size, x, y)) {
                if (board[x-1][y] == 0) {
                    board[x-1][y] = next;
                    transverseBoard(board, size, x-1, y, d);
                    break;
                };
            };
            if (isEastValid(size, x, y)) {
                if (board[x][y+1] == 0) {
                    board[x][y+1] = next;
                    transverseBoard(board, size, x, y+1, d);
                    break;
                };
            };
            if (isWestValid(size, x, y)) {
                if (board[x][y-1] == 0) {
                    board[x][y-1] = next;
                    transverseBoard(board, size, x, y-1, d);
                    break;
                };
            };
            if (isSouthValid(size, x, y)) {
                if (board[x+1][y] == 0) {
                    board[x+1][y] = next;
                    transverseBoard(board, size, x+1, y, d);
                    break;
                };
            };
        };

        case 's': {
            if (isSouthValid(size, x, y)) {
                if (board[x+1][y] == 0) {
                    board[x+1][y] = next;
                    transverseBoard(board, size, x+1, y, d);
                    break;
                };
            };
            if (isEastValid(size, x, y)) {
                if (board[x][y+1] == 0) {
                    board[x][y+1] = next;
                    transverseBoard(board, size, x, y+1, d);
                    break;
                };
            };
            if (isWestValid(size, x, y)) {
                if (board[x][y-1] == 0) {
                    board[x][y-1] = next;
                    transverseBoard(board, size, x, y-1, d);
                    break;
                };
            };
            if (isNorthValid(size, x, y)) {
                if (board[x-1][y] == 0) {
                    board[x-1][y] = next;
                    transverseBoard(board, size, x-1, y, d);
                    break;
                };
            };
        };

        case 'e': {
            if (isEastValid(size, x, y)) {
                if (board[x][y+1] == 0) {
                    board[x][y+1] = next;
                    transverseBoard(board, size, x, y+1, d);
                    break;
                };
            };
            if (isNorthValid(size, x, y)) {
                if (board[x-1][y] == 0) {
                    board[x-1][y] = next;
                    transverseBoard(board, size, x-1, y, d);
                    break;
                };
            };
            if (isSouthValid(size, x, y)) {
                if (board[x+1][y] == 0) {
                    board[x+1][y] = next;
                    transverseBoard(board, size, x+1, y, d);
                    break;
                };
            };
            if (isWestValid(size, x, y)) {
                if (board[x][y-1] == 0) {
                    board[x][y-1] = next;
                    transverseBoard(board, size, x, y-1, d);
                    break;
                };
            };
        };

        case 'w': {
            if (isWestValid(size, x, y)) {
                if (board[x][y-1] == 0) {
                    board[x][y-1] = next;
                    transverseBoard(board, size, x, y-1, d);
                    break;
                };
            };
            if (isNorthValid(size, x, y)) {
                if (board[x-1][y] == 0) {
                    board[x-1][y] = next;
                    transverseBoard(board, size, x-1, y, d);
                    break;
                };
            };
            if (isSouthValid(size, x, y)) {
                if (board[x+1][y] == 0) {
                    board[x+1][y] = next;
                    transverseBoard(board, size, x+1, y, d);
                    break;
                };
            };
            if (isEastValid(size, x, y)) {
                if (board[x][y+1] == 0) {
                    board[x][y+1] = next;
                    transverseBoard(board, size, x, y+1, d);
                    break;
                };
            };
        };
    };

};

int main() {
    int n;
    cin >> n;
    char d;
    cin >> d;
    int x;
    int y;
    cin >> x >> y;
    // initialize board
    // instantiate a n*n board with 0s
    vector< vector<int> > board;
    board.resize(n);
    for (int i=0; i < n; i++){
        board[i].resize(n);
    };
    
    board[x][y] = 1;
    
    transverseBoard(board, n, x, y, d);
    
    return 0;
}


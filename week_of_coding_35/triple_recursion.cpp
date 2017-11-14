#include <bits/stdc++.h>

using namespace std;

void printBoard(int n, vector< vector<int> > board){
    
    for (int i = 0; i<n ; i++){
        for (int j=0; j<n; j++){
            cout << board[i][j] << " ";
        };
        cout << endl;
    };
};

void tripleRecursion(int n, int m, int k) {
    // Complete this function
    
    vector< vector<int> > board;
    board.resize(n);
    for (int i = 0; i < n; i++ ){
        board[i].resize(n);
    };
    
    for (int i = 0; i < n; i++ ){
        for (int j = 0; j < n; j++){
            if ((i == 0) && (j == 0)){
                board[i][j] = m;
            } else if (i == j){
                board[i][j] = board[i-1][j-1] + k;
            } else if (i>j){
                board[i][j] = board[i-1][j] -1;
            } else if (i<j){
                board[i][j] = board[i][j-1]-1;
            };
        };
    };
    
    printBoard(n, board);
    
};

int main() {
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    tripleRecursion(n, m, k);
    return 0;
}


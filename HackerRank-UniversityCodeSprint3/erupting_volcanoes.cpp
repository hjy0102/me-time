#include <bits/stdc++.h>

using namespace std;
int findMax(vector<vector<int> > board, int row, int column){
    int local_max = 0;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (board[i][j] > local_max){
                local_max = board[i][j];
            };
        };
    };
    return local_max;
};

void printBoard(vector<vector<int> > board, int row, int column){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            cout << board[i][j] << " ";
        };
        cout << endl;
    };
};

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    // initialize a n * n board
    vector<vector<int> > board;
    board.resize(n);
    for (int column = 0; column < n; column++){
        board[column].resize(n);
    }; 

    for (int a0 = 0; a0 < m; a0++){
        int x;
        int y;
        int w;
        cin >> x >> y >> w;

        for (int row = 0; row < n; row++){
            for (int column = 0; column < n; column++){
                int x_dist = abs(row - x);
                int y_dist = abs(column - y);
                if ((w-max(x_dist, y_dist)) > 0){
                    board[row][column] =  board[row][column] + w - max(x_dist, y_dist);
                }
            };
        };
    }
    
    int ans = findMax(board, n, n);

    cout << ans << endl;

    return 0;
}

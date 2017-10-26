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

vector<vector<int> > transverseBoard(vector<vector<int> > board, int size, int x, int y, char d){
    int count = board[x][y];
    int next = count + 1;
    printBoard(board, size, size);
    cout << x << " and " << y << endl;
    cout << "count is : " << count << endl;
    if (count >= size*size) return board;
    // check if d is a valid direction to move in
    switch(d){
        case 'n': {
            // move north
            if ((x-1)>=0){
                if (board[x-1][y] < count){
                    cout << "north" <<endl;
                    board[x-1][y] = next;
                    transverseBoard(board, size, (x-1), y, d);
                }
            }
            // move east
            if ((y+1)< size) {
                if (board[x][y+1] < count) {
                    cout << "east" <<endl;
                    board[x][y+1] = next;
                    transverseBoard(board, size, x, (y+1), d);
                }
            }
            // move west
            if ((y-1)>=0){
                if (board[x][y-1] < count) {
                    cout << "west" << endl;
                    board[x][y-1] = next;
                    transverseBoard(board, size, x, (y-1), d);
                }
                
            }
            // move south
            if ((x+1)< size){
                if (board[x+1][y] < count) {
                    cout << "south" <<endl;
                    board[x+1][y] = next;
                    transverseBoard(board, size, (x+1), y, d);
                };
            }
            
            return board;
            
            break;
        }
        case 's': {
            // move south
            if ((x+1)>=0){
                cout << "north" <<endl;
                board[x+1][y] = next;
                transverseBoard(board, size, (x+1), y, d);
            // move east
            } else if ((y+1)< size) {
                cout << "east" <<endl;
                board[x][y+1] = next;
                transverseBoard(board, size, x, (y+1), d);
            // move west
            } else if ((y-1)>=0){
                cout << 'west' << endl;
                board[x][y-1] = next;
                transverseBoard(board, size, x, (y-1), d);
            // move north
            } else if ((x-1)< size){
                cout << "south" <<endl;
                board[x-1][y] = next;
                transverseBoard(board, size, (x-1), y, d);
            } else return board;
            
            break;
        }

        case 'e': {
            // move east
            if ((y+1)< size) {
                cout << "east" <<endl;
                board[x][y+1] = next;
                transverseBoard(board, size, x, (y+1), d); 
            }
            // move north
            else if ((x-1)< size){
                    cout << "south" <<endl;
                    board[x-1][y] = next;
                    transverseBoard(board, size, (x-1), y, d);
            }
            // move south
            else if ((x+1)>=0){
                cout << "north" <<endl;
                board[x+1][y] = next;
                transverseBoard(board, size, (x+1), y, d);
            
            } 
            // move west 
            else if ((y-1)>=0){
                cout << "west" << endl;
                board[x][y-1] = next;
                transverseBoard(board, size, x, (y-1), d);
            }  else return board;
            
            break;
        }

        case 'w': {
            // move east
            if ((y-1)< size) {
                cout << "east" <<endl;
                board[x][y-1] = next;
                transverseBoard(board, size, x, (y-1), d); 
            }
            // move north
            else if ((x-1)< size){
                    cout << "south" <<endl;
                    board[x-1][y] =next;
                    transverseBoard(board, size, (x-1), y, d);
            }
            // move south
            else if ((x+1)>=0){
                cout << "north" <<endl;
                board[x+1][y] = next;
                transverseBoard(board, size, (x+1), y, d);
            
            } 
            // move west 
            else if ((y+1)>=0){
                cout << 'west' << endl;
                board[x][y+1] = next;
                transverseBoard(board, size, x, (y+1), d);
            }  else return board;
            
            break;
        }
                                   
    }

    return board;
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

    printBoard(board, n,n);
    
    vector<vector<int> > ans = transverseBoard(board, n, x, y, d);
    
    printBoard(ans, n, n);
    
    return 0;
}


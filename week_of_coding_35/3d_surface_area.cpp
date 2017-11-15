#include <bits/stdc++.h>

using namespace std;

int surfaceArea(vector < vector<int> > A) {
    // Complete this function
    int H = A.size();
    int W = A[0].size();
    // cout << H << " "<< W << endl;
    int area = 0;
    int top= 0;
    int side = 0 ;
    int front = 0;
    // top 
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (A[i][j] != 0){
                top++;
            };
        };
    };
    // cout << "top :  " << top << endl;

    // front
    int temp_max = 0;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (A[i][j] > temp_max){
                temp_max = A[i][j];
            };
        };
        
        front = front + temp_max;
    };
    // cout << "front :  " << front << endl;

    // side 
    temp_max = 0;
    for (int j = 0; j < W; j++){
        for (int i=0; i < H; i++){
            if (A[i][j] > temp_max){
                temp_max = A[i][j];
            };
        };
        side = side + temp_max;
    };
    
    // cout << "side :  " << side << endl;
    

    
    area = 2*side + 2*top + 2*front;    
    return area;
    
}

int main() {
    int H;
    int W;
    cin >> H >> W;
    vector< vector<int> > A(H,vector<int>(W));
    for(int A_i = 0;A_i < H;A_i++){
       for(int A_j = 0;A_j < W;A_j++){
          cin >> A[A_i][A_j];
       }
    }
    int result = surfaceArea(A);
    cout << result << endl;
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int surfaceArea(vector < vector<int> > A) {
    // Complete this function
    int H = A.size();
    int W = A[0].size();
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
    cout << "top :  " << top << endl;

    // front
    for (int i = 0; i < H; i++){
        int temp_max = 0;
        for (int j = 0; j < W; j++){
            if (A[i][j] > temp_max){
                temp_max = A[i][j];
            };
            if (A[i][j] == 0){
                // cout << "HERE:   A[i][j]    "<< A[i][j] << endl;
                int height_1 = 0;
                int height_2 = 0;
                // cout << "height_1 :  "<< height_1  << endl;
                // cout << "height_2 :  " << height_2 << endl;
                for (int jj = j-1; jj >= 0; jj--){
                    // cout << "FIRST!!!!!!!" <<endl;
                    // cout << "A[i][jj] :  "<< A[i][jj] << endl;
                    if (A[i][jj] != 0){
                        height_1 = A[i][jj];
                        // cout << "height_1 :  "<< height_1  << endl;
                        // cout << "height_2 :  " << height_2 << endl;
                    };
                };
                for (int jj = j+1; jj < W ; jj++){
                    // cout << "SECOND!!!!!!!" <<endl;
                    // cout << "A[i][jj] :  "<< A[i][jj] << endl;
                    if (A[i][jj] != 0){
                        height_2 = A[i][jj];
                        // cout << "height_1 :  "<< height_1  << endl;
                        // cout << "height_2 :  " << height_2 << endl;
                    };
                };
                // cout << "height_1 :  "<< height_1  << endl;
                // cout << "height_2 :  " << height_2 << endl;
                
                front = front + min(height_1, height_2);
                // cout << "front : " << front <<endl;
            };
        };
        
        front = front + temp_max;
    };

    cout << "front :  " << front << endl;

    // side 
    for (int j = 0; j < W; j++){
        int temp_max = 0;
        for (int i=0; i < H; i++){
            if (A[i][j] > temp_max){
                temp_max = A[i][j];
            };

            if (A[i][j] == 0){
                // cout << "HERE:   A[i][j]    "<< A[i][j] << endl;
                int height_1 = 0;
                int height_2 = 0;
                // cout << "height_1 :  "<< height_1  << endl;
                // cout << "height_2 :  " << height_2 << endl;
                for (int ii = i-1; ii >= 0; ii--){
                    // cout << "FIRST!!!!!!!" <<endl;
                    // cout << "A[ii][j] :  "<< A[ii][j] << endl;
                    if (A[ii][j] != 0){
                        height_1 = A[ii][j];
                        // cout << "height_1 :  "<< height_1  << endl;
                        // cout << "height_2 :  " << height_2 << endl;
                    };
                };
                for (int ii = i+1; ii < H ; ii++){
                    // cout << "SECOND!!!!!!!" <<endl;
                    // cout << "A[ii][j] :  "<< A[ii][j] << endl;
                    if (A[ii][j] != 0){
                        height_2 = A[ii][j];
                        // cout << "height_1 :  "<< height_1  << endl;
                        // cout << "height_2 :  " << height_2 << endl;
                    };
                };
                // cout << "height_1 :  "<< height_1  << endl;
                // cout << "height_2 :  " << height_2 << endl;
                
                side = side + min(height_1, height_2);
                // cout << "side : " << side <<endl;
            };

        };
        side = side + temp_max;
    };

    cout << "side :  " << side << endl;
    
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

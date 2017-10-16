#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 2) {
        return -1;
    }

    ifstream fin;
    fin.open (argv[1]);
    if (!fin.is_open()){
        cerr << "unable to open "<< endl;
        return -1;
    }
    string str;
    int matrix[][];
    int row = 0;
    int col = 0;

    while(!fin.eof()){
        istringstream iss(str, istringstream::in);
        stringstream ss(str);
        int i;
        while (ss >> i)
        {
            matrix[row][col] = i;
            if (ss.peek() == ' '){
                ss.ignore();
                col++;
            }
            if (ss.peek() == '\n'){
                ss.ignore();
                row++;
            }
        }

        cout << "row : " << row << endl;
    }

    
}
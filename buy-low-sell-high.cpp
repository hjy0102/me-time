// Intermediate Algorithm Design and Analysis
// UBC CPSC 320 Summer 2017
/**
Suppose we have a 𝑆 = {𝑠1, 𝑠2, ... , 𝑠𝑛} of integer values 
where 𝑠𝑖 represents the price of a stock at time 𝑖. 
Given this historic price data, we wish to (retrospectively) 
find the best time to buy and sell the stock, which should be a 
contiguous interval with the highest jump in price.
Example: 𝑆 = {2,10,3,0,4,0,0,1,3,3,9,0,21,15,17,4} has a 
maximum jump of 21 if purchased at 𝑖 = 4 and sold at 𝑗 = 13.
**/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>
#include <iterator>

using namespace std;

// print function
void printArray(int n, int S[]){

    cout << "This is the list of historic price data :" << endl ; 
    for (int i = 0; i < n; i++){
        cout << S[i] << "   "; 
    }
    cout << endl;
}

// print choice
void printChoice(){
    cout << "Please choose an algorithm :" << endl;
    cout << "1     Brute force" << endl;
    cout << "2     Divide-and-conquer" << endl;
    cout << "Your choice : ";
}

// brute force method
void getRich_BF(int n, int S[]){
    cout << "get Rich by BF" << endl;
    printArray(n, S);

    int p = 0;

    for (int i = 0; i < n-1; i++){
        for (int j= i+1; j < n; j++){
            int p_temp = S[j] - S[i];
            if (p_temp > p) {
                p = p_temp;
            }
        }
    }

    cout << "Max jump value is : " << p << " by brute force." << endl;

}

// divide and conquer method
void getRich_DAC(int n, int S[]) {
    cout << "get Rich by DAC" << endl;
    printArray(n, S);

    int[] minMax;

    if (n == 1) {
        int _min = S[0];
        int _max = S[0];
        minMax = { _min, _max}
        return minMax;
    }

    if (n == 2) {
        if (S[0] < S[1]){
            int _min = S[0];
            int _max = S[1];

        } else {
            int _min = -1;
            int _max = -1;
        }
        minMax = {_min, _max};
        return minMax;
    }

    int[] part1;

}

int main (int argc, char* argv[]){
    int S[] = {2,10,3,0,4,0,0,1,3,3,9,0,21,15,17,4};
    int n = sizeof(S)/sizeof(S[0]);
    printArray(n, S);
    cout << endl;
    printChoice();
    
    int choice;
    cin >> choice;

    cout << choice << endl;

    switch (choice) {
        case (1):
            getRich_BF(n, S);
            return 0;
        case (2):
            getRich_DAC(n, S);
            return 0;
        default: 
            cout << "Your choice was invalid. Default brute force algorithm was selected." <<endl;
            getRich_BF(n, S);
            return 0;
    }
    return -1;
}
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
#include <stdio.h>
#include <math.h>

using namespace std;

//TODO

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
int getRich_DAC(int n, int S[]) {
    cout << "get Rich by DAC" << endl;
    printArray(n, S);
    
    // conquer
    int minMax[2*sizeof(S[0])];
    int _min;
    int _max;

    if (n == 1) {
        _min = S[0];
        _max = S[0];
        minMax[0] = _min;
        minMax[1] = _max;
        return minMax;
    }

    if (n == 2) {
        if (S[0] < S[1]){
            _min = S[0];
            _max = S[1];

        } else {
            _min = -1;
            _max = -1;
        }
        minMax[0] = _min;
        minMax[1] = _max;
        return minMax;
    }
    // divide 

    if (n > 2) {
        int p1 = ceil(n/2);
        int p2 = n - p1;

        int S1[p1];
        int S2[p2];

        for (int i = 0; i < p1; i++){
            S1[i] = S[i];
        }

        for (int j = p1; j < p2; j++){
            S2[j] = S[j];
        }

        int part1[2] = getRich_DAC(p1, S1);
        int part2[2] = getRich_DAC(p2, S2);

        if ((part2[1]-part2[0]) > (part1[1]- part1[0])) {
            minMax[0] = part2[0];
            minMax[1] = part2[1];
        } else {
            minMax[0] = part1[0];
            minMax[1] = max(part1[1], part2[1]);
        }

        return minMax;
    }
}

void printValue_DAC(int n, int S[]){
    int m[2] = getRich_DAC(n, S);
    int value = m[1] - m[0];
    if (value > -1){
        cout << "Max jump value is : " << value << " by divide-and-conquer." << endl;
    } else {
        cout << "Error ... " <<endl;
    }
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
            printValue_DAC(n, S);
            return 0;
        default: 
            cout << "Your choice was invalid. Default brute force algorithm was selected." <<endl;
            getRich_BF(n, S);
            return 0;
    }
    return -1;
}
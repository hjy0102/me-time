/**
 * The Coin Change Problem
 * You have  types of coins available in infinite quantities where the value of each coin
 * is given in the array . 
 * Can you determine the number of ways of making change for 
 * units using the given types of coins? 
 * 
 * m = number of coins in array C
 * n = desired value
 * 
 * using memoization : 
 *  create an (m+1) * (n+1) table 
 **/

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

long waystosum(int sum, vector<int> coins) {
    vector<long> memo(sum + 1);
    memo[0] = 1;
    for (auto &coin : coins) {
        for (int i = coin; i <= sum; i++) {
            memo[i] += memo[i-coin];
        }
    }
    return memo[sum];
}

int main() {
    int sum, numcoins;
    vector<int> coins;
    cin >> sum >> numcoins;
    int tempcoin;
    for (int i = 0; i < numcoins; i++) {
        cin >> tempcoin;
        coins.push_back(tempcoin);
    }

    cout << waystosum(sum, coins) << endl;
    return 0;
}
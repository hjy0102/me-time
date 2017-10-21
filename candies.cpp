#include <bits/stdc++.h>

using namespace std;


int candies(int n, vector <int> arr) {
    int totalCandies = 0;

    vector<int> memo = vector<int>(n, 1);
    
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] < arr[i])
            memo[i] = 1 + memo[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i - 1] > arr[i])
            memo[i-1] = max(memo[i]+1, memo[i-1]);
    }

    for (int i = 0; i < n; i++) {
        totalCandies += memo[i];
    }

    return totalCandies;
    
}


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = candies(n, arr);
    cout << result << endl;
    
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

long candies(int n, vector <int> arr) {
    long totalCandies = 0;

    vector<long> left = vector<long>(n, 1);
    vector<long> right = vector<long>(n, 1);
    
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i + 1] < arr[i])
            right[i] = 1 + right[i + 1];
    }

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] < arr[i])
            left[i] = 1 + left[i - 1];
    }

    for (int i = 0; i < n; i++) {
        totalCandies += max(right[i], left[i]);
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
    long result = candies(n, arr);
    cout << result << endl;
    return 0;
}
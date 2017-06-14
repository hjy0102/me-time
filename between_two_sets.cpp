/*
O(sqrt(C)) where C is the total number of elements in A and in B.
1. find the LCM of all the integers of array A.
2. find the GCD of all the integers of array B.
3. Count the number of multiples of LCM that evenly divides the GCD.
*/

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <set>

const int maxc = 100;

#define forn(i,n) for (int i = 0; i < n; i++)

using namespace std;

int gcd(int a, int b) {
    while (a && b) {
        if (a >= b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main(){
    #ifdef LOCAL
    assert(freopen("test.in", "r", stdin));
    #endif

    int n,m;
    cin >> n >> m;

    int A = 1, B = 0;

    forn (i, n) {
        int x; 
        cin >> x;
        A = lcm(A, x);
        if (A > maxc) {
            cout << 0 << '\n';
            return 0;
        }

    }

    if (B % A != 0) {
        cout << 0 << '\n';
        return 0;
    }

    B /= A; 
    int res = 0;
    for (int i = 1; i * i <= B; i++){
        if (B % i == 0){
            ++res;
            if (i * i != B){
                res++;
            }
        }
    }
    cout << res<< '\n';
}
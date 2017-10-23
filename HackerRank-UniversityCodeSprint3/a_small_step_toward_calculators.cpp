#include <bits/stdc++.h>
#include <string>

using namespace std;

int solve(string opr) {
    // Complete this function
    
    if (opr.length() != 3) {
        return -1;
    };
    
    string first = opr.substr(0,1);
    string arith = opr.substr(1,1);
    string second = opr.substr(2,3);
            
    if (arith == "-"){
        return atoi(first.c_str()) - atoi(second.c_str());
    } else if (arith == "+"){
        return atoi(first.c_str()) + atoi(second.c_str());
    }
    return 0;
}

int main() {
    string opr;
    cin >> opr;
    int result = solve(opr);
    cout << result << endl;
    return 0;
}

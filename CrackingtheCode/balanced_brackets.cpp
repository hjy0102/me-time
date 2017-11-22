#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool is_balanced(string expression) {
    stack<char> myStack; 
    char a, b, c;
    int length = expression.length();
    
    for (int i = 0; i < length; i++){
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
            myStack.push(expression[i]);
        } else {
            switch(expression[i]){
                case ')':
                    if ( myStack.empty() ){
                        return false;
                    }
                    a = myStack.top();
                    myStack.pop();
                    if (a == '{' || a == '['){
                        return false;
                    };
                    break;
                case '}':
                    if ( myStack.empty() ){
                        return false;
                    }
                    b = myStack.top();
                    myStack.pop();
                    if (b == '(' || b  == '[' ){
                        return false;
                    };
                    break;
                case ']':
                    if ( myStack.empty() ){
                        return false;
                    };
                    c = myStack.top();
                    myStack.pop();
                    if (c == '{' || c == '('){
                        return false;
                    };
                    break;
            };
        };
    };
    
    // Check Empty Stack
    if (myStack.empty())
        return true;
    else
        return false;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
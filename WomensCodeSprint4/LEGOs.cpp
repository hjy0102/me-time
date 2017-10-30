#include <bits/stdc++.h>

using namespace std;

int productOfLegos(int a, int b, int c, int d, int p, int q) {
    // Return the product of the page counts of the missing books
    vector<int> ans;
    ans.push_back(a);
    ans.push_back(b);
    ans.push_back(c);
    ans.push_back(d);
    
    vector<int> check;
    check.push_back(p);
    check.push_back(q);
    
    while (!check.empty()){
        for (int i = 0; i < ans.size() ; i++){
            if (check.back() == ans[i]){
                check.pop_back();
                ans.erase(ans.begin()+i);
            }
        }
    }
    return ans[0] * ans[1];
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int a;
        int b;
        int c;
        int d;
        cin >> a >> b >> c >> d;
        int p;
        int q;
        cin >> p >> q;
        int answer = productOfLegos(a, b, c, d, p, q);
        cout << answer << endl;
    }
    return 0;
}
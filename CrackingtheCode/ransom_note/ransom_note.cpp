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

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    int m = magazine.size();
    int n = ransom.size();

    if  (m >= n) {
        unordered_map<string, int> wordMap;
        
        for (int i=0; i < m; i++){
            wordMap[magazine[i]] = wordMap[magazine[i]]+1;
        }
        
        for (int j=0; j< n; j++){
            int ans = wordMap[ransom[j]];
            if (ans < 1) {
                return false;
            } else {
                wordMap[ransom[j]] = wordMap[ransom[j]] - 1;
            }
        }
        
        return true;
    }
    return false;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
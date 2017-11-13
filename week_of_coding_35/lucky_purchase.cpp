#include <bits/stdc++.h>

using namespace std;

bool checkForDigits(int value){
    bool ans = true;
    int seven_count = 0; 
    int four_count = 0;
    
    while (value != 0){
        int check = value % 10 ; 
        if ((check != 4) && (check != 7)) {
            ans = false;
            value = 0;
        }
        if (check == 4){
            four_count++;
        }
        if (check == 7){
            seven_count++;
        }
        value = value / 10;
    }

    return ((seven_count == four_count) && ans);
}

int findPrice(vector<int> prices){
    
    
    int price = prices[0];
    for (int i = 0; i < prices.size(); i++ ){
        if (prices[i] < price) {
            price = prices[i];
            
        }
    }
    return price;
}

int main() {
    int n;
    cin >> n;
    
    unordered_map< int, string> books;
    vector<int> prices;
    
    for(int a0 = 0; a0 < n; a0++){
        string name;
        int value;
        cin >> name >> value;
        
        if (checkForDigits(value) ) {
            books[value] = name;
            prices.push_back(value);
        }

    }
    
    if (prices.size() == 0) {
        cout << "-1" << endl;
        return -1;
    }

    int bestPrice = findPrice(prices);
    string book = books.at(bestPrice);
    
    cout << book << endl;
    return 0;
}


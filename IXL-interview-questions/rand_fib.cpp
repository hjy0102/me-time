/**
 * Questions are taken from Glassdoor reviews of previous candidates 
 * and may not be accurate or reflect the actual difficulty of interview questions
 * 
 * Prompt:
 * 
 * generate a random fibonacci number, given an upperbound.
 * 
 **/
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

// recursive fibonnaci number
int rfib(int n){
    if (n <= 1) return n;

    return rfib(n-1) + rfib(n-2);
};

int dfib(int n){
    int f[n+1];
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++){
        f[i] = f[i-1] + f[i-2];
    };

    return f[n];
};

// given an upperbound how many fib numbers are less than the upperbound
int validFibNumbers(int n){
    int i = 0;
    while (dfib(i) < n) {
        i++;
    }
    // including zero
    return i+1;
};

int upperFib(int n){
    std::srand(std::time(0)); // use current time as seed for random generator
    int random_variable = std::rand();

    int total = validFibNumbers(n);
    // hashfunction
    int key = (random_variable * 13) % total;

    return dfib(key);
}

int main(){
    cout << "Please choose: "<< endl;
    cout << "1. recursive fibonacci" <<endl;
    cout << "2. dynamic fibonacci" << endl;
    cout << "3. Random fibonacci given an upper bound"<<endl;
    int choice;
    cin >> choice;

    switch (choice){
        case 1: {
            cout<< "Please provide a positive integer" <<endl;
            int n;
            cin >> n;
            cout << "Fib number: " << rfib(n) <<endl;
            return 0;
        }
        case 2: {
            cout<< "Please provide a positive integer" <<endl;
            int n;
            cin >> n;
            cout << "Fib number: " << dfib(n) <<endl;
            return 0;
        }
        case 3: {
            cout<< "Please provide a upperbound" <<endl;
            int n;
            cin >> n;
            cout << "Fib number: " << upperFib(n) <<endl;
            return 0;
        }
    }


}; 
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        return -1;
    }

    ifstream fin;
    fin.open (argv[1]);
    if (!fin.is_open()){
        cerr << "unable to open"<< endl;
        return -1;
    }
    string str;
    while(!fin.eof()){
        cout << getline(fin, str) << endl;

        istringstream iss(str, istringstream::in);
    }

    vector<int> vect;
    stringstream ss(str);

    int i;

    while (ss >> i)
    {
        vect.push_back(i);
        if (ss.peek() == ',' || ss.peek() == ' ' )
            ss.ignore();
    }
    double totalSum;
    for (i=0; i< vect.size(); i++){
        // cout << vect.at(i)<<endl;
        totalSum = totalSum + vect.at(i);
    }
    cout << "totalSum is " << totalSum << endl;
    cout << "size is " << vect.size() << endl;
    
    double avg = totalSum / vect.size();
    //double remainder = totalSum % (double)vect.size();
    //cout << "remainder is: " << remainder << endl;
    
    // if (avg * vect.size() < totalSum){
    //     avg = avg+1;
    // }
    cout<<setprecision(2)<<fixed<< totalSum / vect.size()<<endl;
    cout <<"average is: "<<setprecision(0)<<fixed<< round(avg) << endl;
    
    return 0;
    

}
#include <iostream>
using namespace std;

int& increment(int &x) {
    x++;
    return x;
}

int main() {
    int a = 10;
    int &aref = a;                         // independent ref
    int &ref = increment(aref);           // ref funct
    
    cout << "a: " << aref << endl;  
    cout << "ref: " << ref << endl; 
    
    ref++;
    cout << "a: " << aref << endl;
    cout << "ref: " << ref << endl;

    return 0;
}

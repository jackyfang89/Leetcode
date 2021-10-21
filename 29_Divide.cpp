#include<iostream>
#include <climits>
using namespace std;

//divide without mult, div, mod
//return dividend / divisor
int divide(int dividend, int divisor) {
    //overflow case
    if (dividend == INT32_MIN && divisor == -1) return INT32_MAX;

    //bit manipulation
    
}

int main(int argc, char* argv[]) {
    cout << divide(stoi(argv[1]), stoi(argv[2])) << endl;
    return 0;
}
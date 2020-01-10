#include <iostream>

using namespace std; 
#define sill 2147483647

unsigned long long int power(int x, unsigned int y) { 
    unsigned long long int temp; 

    if( y == 0) 
        return 1; 

    temp = power(x, y/2); 
    temp %= sill;
    
    if (y%2 == 0) 
        return (temp*temp)%sill; 
    else
        return (x*temp*temp)%sill; 
}  

int main() {
    int inputNum;
    cin >> inputNum;

    cout << power(3, inputNum) << endl;
    return 0;
}
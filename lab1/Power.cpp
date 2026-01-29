#include<iostream>
using namespace std;

int power(int num, int p){
    if(p <= 0) return 1;
    if(p == 1) return num;
    else{
        return num * power(num, p - 1);
    }
} 

int main(){
    int num, pwr, pow_iter = 1, pow = 1;
    cout << "Enter the number : ";
    cin >> num;
    for(int i = 0; i <= 100; i = i + 5){
        pwr = i;
    }

    // iterative method
    for(int i = 1; i <= pwr; i ++){
        pow_iter = pow_iter * num;
    }
    cout << num << " raise to power " << pwr << " is : " << pow << endl;

    // reccursive method
    cout << num << " raise to power " << pwr << " is : " << power(num, pwr);

    // time complexity of order of n/2
    while(num != 0){
        if(num % 2 == 0){
            
        } 
    }
}
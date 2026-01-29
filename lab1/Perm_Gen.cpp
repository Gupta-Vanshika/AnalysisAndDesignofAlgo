#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>

using namespace std;
const int MAXSIZE = 100;


void perm_gen( int str[], int k, int str_len){
    if(k == str_len - 1){
        for(int i = 0; i < str_len; i ++){
            cout << str[i];
        }
        cout << " ";
        return;
    }
    else{
        for(int i = k; i < str_len; i ++){
            swap(str[i], str[k]);
            perm_gen(str, k + 1, str_len);
            swap(str[i], str[k]);
        }
        return; 
    }
}

int main(){
    int str_length, str[MAXSIZE], k;
    clock_t start, end;
    double clock_time_use;

    
    ofstream outputFile("Perm_performance_data.txt");    
    outputFile << "Array Size\tTime (ms)" << endl; 

    srand(time(0));
    for(int i = 2; i <= 6; i ++){
        str_length = i;

        cout << "Number is : ";
        for(int i = 0; i < str_length; i ++){
            str[i] = rand()/10000;
            cout << str[i];
        }
        cout << endl;

        start = clock();
        perm_gen(str, 0, str_length);
        cout << endl;
        end = clock();

        clock_time_use = (double(end - start))/CLOCKS_PER_SEC * 1000000000;

        cout << str_length << " " << clock_time_use << endl;
        outputFile << str_length << "\t\t" << clock_time_use << endl;
    }
    outputFile.close();
    cout << "\nData has been saved to 'Perm_performance_data.txt'" << endl;
}
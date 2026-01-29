#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>

using namespace std;
const int MAX_SIZE = 100;

int linear_search(int arr[], int size, int k, int key){
    if(k == size) return 0;
    if(arr[k] == key) return k + 1;
    else{
        return linear_search(arr, size, k + 1, key);
    }
}

int main(){
    int arr[MAX_SIZE], size, key, pos;
    clock_t start, end;
    double clock_per_time;
    srand(time(0));
    for(int i = 5; i <= 100; i = i + 5){
        size = i;

        cout << "Elements of array : ";
        for(int i = 0; i < size; i ++){
            arr[i] = rand()/100;
            cout << arr[i] << " ";
        }
        cout << endl;
        key = arr[size -1];
        cout << "key = " << key << endl;

        start = clock();
        pos = linear_search(arr, size, 0, key);
        cout << pos << endl;
        end = clock();

        clock_per_time = (double(end - start)) / CLOCKS_PER_SEC * 1000000000;
        cout << size << "  " << clock_per_time << " ns" << endl;
    }
}
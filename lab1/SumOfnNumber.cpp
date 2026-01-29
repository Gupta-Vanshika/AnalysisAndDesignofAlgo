#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>

using namespace std;
const int MAXSIZE = 150;

int sum_of_num(int arr[], int n){
    if(n == 0){
        return 0;
    }
    else{
        return arr[n - 1] + sum_of_num(arr, n - 1);
    }
}

int main(){
    int arr[MAXSIZE], sum1, sum2;
    clock_t start1, end1, start2, end2;
    long double cpu_time_used1, cpu_time_used2;

    ofstream outputFile("Sumperformance_data.txt");    
    outputFile << "Array Size\tTime (ms)" << endl; 
    
    srand(time(0));

    for(int size = 5; size <= 100; size = size + 5){
        sum1 = sum2 = 0;
        cout << "Elements in array : " << endl;
        for(int i = 0; i < size; i ++){
            arr[i] = rand()/100;
            cout << arr[i] << "  ";
        }
        cout << endl;

        // Iterative Sum
        start1 = clock();
        for(int i = 0; i < size; i ++){
            sum1 += arr[i];
        }
        cout << "The sum of elements in array(using iterartion) is : " << sum1 << endl;
        end1 = clock();
        cpu_time_used1 = (double(end1 - start1))/ CLOCKS_PER_SEC * 1000000000; 

        // Recursive Sum
        start2 = clock();
        sum2 = sum_of_num(arr, size);
        cout << "The sum of elements in array(using recursion) is : " << sum2 << endl;
        end2 = clock();
        cpu_time_used2 = (double(end2 - start2))/ CLOCKS_PER_SEC * 1000000000; 

        cout << size << "  " << cpu_time_used1 << " ns(iter) " << cpu_time_used2 << " ns(rec) " << endl;
        outputFile << size << "\t\t" << cpu_time_used1 << "\t\t" << cpu_time_used2 << endl;
    }

    outputFile.close();
    cout << "\nData has been saved to 'Sumperformance_data.txt'" << endl;
    
}
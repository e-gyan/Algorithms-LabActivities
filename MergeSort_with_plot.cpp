/**
*mergeSort_with_plot_graph.cpp: To sort a random generated numbers of arrays
*using the merge sort approach
*Date: 23-02-2020
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//MergeSort function
void mergeSort(int arr[], int start, int finish, int arrEmpty[]);

//Random Numbers function
void randomElement(int arr[], int arrEmpty[], int arraySize);

//Output of the array
void display(int arr[], int arraySize);


int main()
{
    int arraySize;

    // Message to the user
    cout << endl << "Enter the size of the item(s): ";
    cin >> arraySize;

    int arr[arraySize], arrEmpty[arraySize];

    // A random generator for set of arrays to be sorted
    cout << endl << "Random number(s) to be sorted using merge sort: ";

    //A void function that generates the random numbers
    randomElement(arr, arrEmpty, arraySize);

    //A void function to sort the arrays using merge sort
    mergeSort(arr, 0, arraySize - 1, arrEmpty);

    //Output of the sorted array
    display(arr, arraySize);

    return 0;
}

void mergeSort(int arr[], int start, int finish, int arrEmpty[]){
    if(finish <= start){
        return;
    }

    int arrDivide = (start + finish) / 2;

    mergeSort(arr, start, arrDivide, arrEmpty);
    mergeSort(arr, arrDivide + 1, finish, arrEmpty);

    int leftSort = start, rightSort = arrDivide + 1, counter;

    for(counter = start; counter <= finish; counter++){
        if(leftSort == arrDivide + 1){
            arrEmpty[counter] = arr[rightSort];
            rightSort++;
        }

        else if(rightSort == finish + 1){
            arrEmpty[counter] = arr[leftSort];
            leftSort++;
        }

        else if(arr[leftSort] < arr[rightSort]){
            arrEmpty[counter] = arr[leftSort];
            leftSort++;
        }

        else{
           arrEmpty[counter] = arr[rightSort];
            rightSort++;
        }

    }

    for(counter = start; counter <= finish; counter++){
        arr[counter] = arrEmpty[counter];
    }

}


void randomElement(int arr[], int arrEmpty[], int arraySize){

    srand((unsigned) time(0));
    int randomValue;

    for(int initial = 0; initial < arraySize; initial++){
        randomValue = (rand() % 100) + 1;

        arr[initial] = randomValue;
        arrEmpty[initial] = 0;
        cout << randomValue << " ";

    }

}


void display(int arr[], int arraySize){
    cout << endl;
    cout << endl << "The sorted is: ";
    for(int i = 0; i < arraySize; i++)
        cout << arr[i] << " ";

    cout << endl;
}

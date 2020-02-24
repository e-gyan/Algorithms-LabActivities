#include <iostream>

using namespace std;

int linearSearch(int arr[], int searchKey, int arraySize);
int Max_Value(int arr[], int start, int arraySize);
int Min_Value(int arr[], int start, int arraySize);

int main()
{
    int arraySize, indexPosition = 0, searchKey, maxValue, minValue;

    cout << endl << "Enter the size of the array: ";
    cin >> arraySize;

    int arrayValues[arraySize];
    for(int i = 0; i < arraySize; i++){
        cout << endl << "Enter array element " << i + 1 << ": ";
        cin >> arrayValues[i];
    }

    cout << endl << "Search for a value: ";
    cin >> searchKey;

    indexPosition = linearSearch(arrayValues, searchKey, arraySize);
    maxValue = Max_Value(arrayValues, 0, arraySize);
    minValue = Min_Value(arrayValues, 0, arraySize);

    if(indexPosition == -1){
        cout << "\nSearched value not found..." << endl;
    }

    else{
        cout << "\nSearched value " << searchKey << " is found at position " << indexPosition << endl;
    }

    cout << "\nThe array maximum value: " << maxValue << " and minimum value: " << minValue << endl;

    return 0;
}

int linearSearch(int arr[], int searchKey, int arraySize){

    if(arraySize == 0)
        return -1;

    else if (searchKey == arr[arraySize - 1])
        return arraySize;

    else
        return linearSearch(arr, searchKey, arraySize - 1);
}



int Max_Value(int arr[], int start, int arraySize){
    int maximum;

    if(start >= arraySize - 2){
        if(arr[start] > arr[start + 1])
            return arr[start];

        else
            return arr[start + 1];
    }

    maximum = Max_Value(arr, start + 1, arraySize);
    if(arr[start] > maximum)
        return arr[start];

    else
        return maximum;
}


int Min_Value(int arr[], int start, int arraySize){
    int minimum;

    if(start >= arraySize - 2){
        if(arr[start] < arr[start + 1])
            return arr[start];

        else
            return arr[start + 1];
    }

    minimum = Min_Value(arr, start + 1, arraySize);
    if(arr[start] < minimum)
        return arr[start];

    else
        return minimum;
}




#include <iostream>

using namespace std;

void bubbleSort(int arrayValue[], int number);
void display(int arrayValue[], int arraySize);
void userInput(int arrayValue[], int arrayOption);

int main()
{
    int arraySize;

    cout << "\nA program to sort an array of element using Bubble sort algorithm" << endl;
    cout << endl << "Enter the size of the array: ";
    cin >> arraySize;

    int arrayValue[arraySize];

    userInput(arrayValue, arraySize);

    bubbleSort(arrayValue, arraySize);

    display(arrayValue, arraySize);

    return 0;
}

void bubbleSort(int arrayValue[], int number){
    int tempValue;
    for(int i = 0; i < number - 1; i++){
        for(int j = 0; j < number - i - 1; j++){
            if(arrayValue[j] > arrayValue[j + 1]){
                tempValue  = arrayValue[j];
                arrayValue[j] = arrayValue[j + 1];
                arrayValue[j + 1] = tempValue;
            }
        }
    }
}

void display(int arrayValue[], int arraySize){
    cout << endl << "Sorting array element in ascending order: ";
    for(int i = 0; i < arraySize; i++){
        cout << arrayValue[i] << " ";
    }

    cout << endl;
}

void userInput(int arrayValue[], int arrayOption){
    for(int i = 0; i < arrayOption; i++){
        cout << endl << "Enter element value " << i + 1 << ": ";
        cin >> arrayValue[i];
    }
}

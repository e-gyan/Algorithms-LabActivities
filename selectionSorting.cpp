#include <iostream>

using namespace std;

void selectionSort(int arrayValue[], int number);
void display(int arrayValue[], int arraySize);
void userInput(int arrayValue[], int arrayOption);

int main()
{
    int arraySize;

    cout << "\nA program to sort an array of element using Selection sort algorithm" << endl;
    cout << endl << "Enter the size of the array: ";
    cin >> arraySize;

    int arrayValue[arraySize];

    userInput(arrayValue, arraySize);

    selectionSort(arrayValue, arraySize);

    display(arrayValue, arraySize);

    return 0;
}

void selectionSort(int arrayValue[], int number){
    int initialPosition, tempValue;

    for(int i = 0; i < number - 1; i++){
            initialPosition = i;
        for(int j = i + 1; j < number; j++){
            if(arrayValue[initialPosition] > arrayValue[j])
                initialPosition = j;
        }

        if(initialPosition != i){
            tempValue  = arrayValue[i];
            arrayValue[i] = arrayValue[initialPosition];
            arrayValue[initialPosition] = tempValue;
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

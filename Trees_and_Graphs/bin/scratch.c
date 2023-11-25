
/*
int main3() {
    int arraySize = 5;

    int arr[5] = { 7, 4, 5, 8, 22 };
    int temp;
    int sortedIndices[5];

    for (int i = 0; i < arraySize; i++) {
        sortedIndices[i] = i;
    }

    //Bubble sorting the indices
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < arraySize - 1; j++) {
            if (arr[sortedIndices[j]] > arr[sortedIndices[i]]) {
                //swap them
                temp = sortedIndices[i];
                sortedIndices[i] = sortedIndices[j];
                sortedIndices[j] = temp;
            }
        }
    }

    cout << "Original Array\n";
    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Sorted array\n";
    for (int i = 0; i < arraySize; i++) {
        cout << arr[sortedIndices[i]] << " ";
    }
    cout << endl;

    cout<<"Sorted indices are\n";
    for (int i = 0; i < arraySize; i++) {
        cout << sortedIndices[i] << " ";
    }
}
*/
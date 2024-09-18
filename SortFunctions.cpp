//Assignment 2 of DevOps

#include <bits/stdc++.h>

using namespace std;

enum class SortAlgorithm {
    BUBBLE_SORT,
    MERGE_SORT,
    QUICK_SORT,
    // Add other sorting algorithms here if not mentioned and also change the sortArray function accordingly and the cout in selecting the sorting algorithm
};

// Name of Contributor
void bubbleSort(vector<int>& arr) {
    
}

void mergeSort(vector<int>& arr) {
    
}

void quickSort(vector<int>& arr) {

}
void insertionSort(vector<int>& arr){
    for(int i = 1;i < arr.size() ; i++){
        int key = arr[i];
        int j = i-1;
        while(j>0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key
    }
}

void sortArray(vector<int>& arr, SortAlgorithm algorithm) {
    switch (algorithm) {
        case SortAlgorithm::BUBBLE_SORT:
            bubbleSort(arr);
            break;
        case SortAlgorithm::MERGE_SORT:
            mergeSort(arr);
            break;
        case SortAlgorithm::QUICK_SORT:
            quickSort(arr);
            break;
        default:
            cerr << "Invalid sorting algorithm selected." << endl;
            break;
    }
}

int main() {
    int numElements;
    cout << "Enter the number of elements: ";
    cin >> numElements;

    vector<int> arr(numElements);
    cout << "Enter the elements: ";
    for (int i = 0; i < numElements; ++i) {
        cin >> arr[i];
    }

    int choice;
    cout << "Choose sorting algorithm (0: Bubble, 1: Merge, 2: Quick): ";
    cin >> choice;

    SortAlgorithm algorithm = static_cast<SortAlgorithm>(choice);
    sortArray(arr, algorithm);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

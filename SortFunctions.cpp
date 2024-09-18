#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

enum class SortAlgorithm {
    BUBBLE_SORT,
    MERGE_SORT,
    QUICK_SORT,
    BUCKET_SORT
};

// Function to perform insertion sort (used inside bucket sort)
void insertionSort(std::vector<double>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bucket Sort algorithm
void bucketSort(std::vector<double>& arr) {
    if (arr.empty()) return;

    // Determine the number of buckets
    int numBuckets = std::round(std::sqrt(arr.size()));
    double maxValue = *std::max_element(arr.begin(), arr.end());
    double minValue = *std::min_element(arr.begin(), arr.end());

    // Create buckets and distribute the elements
    std::vector<std::vector<double>> buckets(numBuckets);
    double bucketRange = (maxValue - minValue) / numBuckets;

    for (double num : arr) {
        int index = static_cast<int>((num - minValue) / bucketRange);
        if (index == numBuckets) index--; // Edge case where the number is exactly maxValue
        buckets[index].push_back(num);
    }

    // Sort each bucket and concatenate the results
    arr.clear();
    for (auto& bucket : buckets) {
        insertionSort(bucket);
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}

// Bubble Sort algorithm
void bubbleSort(std::vector<double>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to merge two subarrays into a single sorted array
void merge(std::vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<double> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<double> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive merge sort function
void mergeSort(std::vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort algorithm
int partition(std::vector<double>& arr, int low, int high) {
    double pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<double>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Sort the array based on the chosen algorithm
void sortArray(std::vector<double>& arr, SortAlgorithm algorithm) {
    switch (algorithm) {
        case SortAlgorithm::BUBBLE_SORT:
            bubbleSort(arr);
            break;
        case SortAlgorithm::MERGE_SORT:
            mergeSort(arr, 0, arr.size() - 1);
            break;
        case SortAlgorithm::QUICK_SORT:
            quickSort(arr, 0, arr.size() - 1);
            break;
        case SortAlgorithm::BUCKET_SORT:
            bucketSort(arr);
            break;
        default:
            std::cout << "Invalid sorting algorithm selected." << std::endl;
    }
}

int main() {
    int numElements;
    std::cout << "Enter the number of elements: ";
    std::cin >> numElements;

    std::vector<double> arr(numElements);
    std::cout << "Enter the elements: " << std::endl;
    for (int i = 0; i < numElements; i++) {
        std::cin >> arr[i];
    }

    int choice;
    std::cout << "Choose sorting algorithm (0: Bubble, 1: Merge, 2: Quick, 3: Bucket): ";
    std::cin >> choice;

    SortAlgorithm algorithm = static_cast<SortAlgorithm>(choice);

    sortArray(arr, algorithm);

    std::cout << "Sorted array: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
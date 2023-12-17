// question 3
#include<iostream>
#include<algorithm>
#include<numeric> 

using namespace std;

// Function to find minimum, maximum, and average of array elements
int findMinMaxAvg(int arr[], int size) {
    if (size <= 0) {
        cout << "Array is empty." << endl;
        return 1;
    }

    int minVal = *min_element(arr, arr + size);
    int maxVal = *max_element(arr, arr + size);
    double avgVal = accumulate(arr, arr + size, 0.0) / size; // Fix accumulate function

    cout << "Minimum value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;
    cout << "Average value: " << avgVal << endl;

    return 0;
}

// Function for linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            cout << "Element found using linear search.\n";
            return 0;
        }
    }
    cout << "Element not found.\n";
    return 1;
}

// Function for binary search (iterative version)
int binarySearchIterative(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            cout << "Element found using binary search (iterative).\n";
            return 0;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << "Element not found.\n";
    return 1;
}

// Function for binary search (recursive version)
int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            cout << "Element found using binary search (recursive).\n";
            return 0;
        } else if (arr[mid] < target) {
            return binarySearchRecursive(arr, mid + 1, high, target);
        } else {
            return binarySearchRecursive(arr, low, mid - 1, target);
        }
    }

    cout << "Element not found.\n";
    return 1;
}

// Function to display addresses of array elements
int displayAddresses(int arr[], int size) {
    cout << "Addresses of array elements:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Element " << arr[i] << " at address: " << &arr[i] << endl;
    }
    return 0;
}

int main() {
    int choice;
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Find minimum, maximum, and average of array elements\n";
        cout << "2. Search an element in the array using linear search\n";
        cout << "3. Search an element in the array using binary search (iterative)\n";
        cout << "4. Search an element in the array using binary search (recursive)\n";
        cout << "5. Display the address of every element of the array\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                return findMinMaxAvg(arr, size);

            case 2:
                int targetLinear;
                cout << "Enter the element to search: ";
                cin >> targetLinear;
                return linearSearch(arr, size, targetLinear);

            case 3:
                int targetBinaryIterative;
                cout << "Enter the element to search: ";
                cin >> targetBinaryIterative;
                return binarySearchIterative(arr, size, targetBinaryIterative);

            case 4:
                int targetBinaryRecursive;
                cout << "Enter the element to search: ";
                cin >> targetBinaryRecursive;
                return binarySearchRecursive(arr, 0, size - 1, targetBinaryRecursive);

            case 5:
                return displayAddresses(arr, size);

            case 6:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}

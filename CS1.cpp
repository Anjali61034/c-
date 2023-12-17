/* // question 1
#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char *argv[]) {
    int n;

    // Check if command line argument is provided
    if (argc > 1) {
        n = atoi(argv[1]);  // Convert command line argument to integer
    } else {
        // Prompt user to enter the value of n
        cout << "Enter the value of n: ";
        cin >> n;
    }

    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        // Calculate each term of the series
        double term = pow(-2, i) + pow(3, i) - pow(4, i);
        sum += term;
    }

    // Display the sum of the series
    cout << "Sum of the series for the first " << n << " terms: " << sum << endl;

    return 0;
}
// question 2
#include<iostream>

using namespace std;

int main() {
    int n;

    // Prompt user to enter the number of rows
    cout << "Enter the number of rows (n): ";
    cin >> n;

    // Loop to iterate through each row
    for (int i = 0; i < n; ++i) {
        // Loop to print characters for each row
        for (int j = i; j >= 0; --j) {
            // Print characters in reverse order (CBA)
            cout << char('A' + j);
        }

        // Move to the next line after each row
        cout << endl;
    }

    return 0;
}
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
// question 4
#include<iostream>

using namespace std;

void printFactors(int number, int divisor = 1) {
    while (divisor <= number) {
        if (number % divisor == 0) {
            cout << divisor << " "; // Print the factor
        }
        divisor++;
    }
}

int main() {
    int inputNumber;

    cout << "Enter a number: ";
    cin >> inputNumber;

    cout << "Factors of " << inputNumber << " are: ";
    printFactors(inputNumber);

    return 0;
}
// question 5
#include<iostream>
#include<cctype> // For isupper function

using namespace std;

// Function to calculate the length of the string using pointers
int calculateLength(const char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

// Function to check if the first character of the string is in uppercase
bool isFirstCharUppercase(const char* str) {
    while (*str != '\0' && *str == ' ') {
        str++; // Skip leading spaces
    }

    if (*str != '\0' && isupper(*str)) {
        return true;
    }
    return false;
}

// Function to reverse the string using pointers
void reverseString(char* str) {
    char* start = str;
    char* end = str + calculateLength(str) - 1;

    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }
}

// Function to display the address of every character in the string
void displayAddresses(const char* str) {
    cout << "Addresses of characters in the string:" << endl;
    while (*str != '\0') {
        cout << "Character '" << *str << "' at address: " << static_cast<const void*>(str) << endl;
        str++;
    }
}

int main() {
    const int MAX_SIZE = 100;
    char inputString[MAX_SIZE];

    cout << "Enter a string: ";
    cin.getline(inputString, MAX_SIZE);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Calculate length of the string\n";
        cout << "2. Check if the first character of the string is in uppercase\n";
        cout << "3. Reverse the string\n";
        cout << "4. Display addresses of every character in the string\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Length of the string: " << calculateLength(inputString) << endl;
                break;

            case 2:
                cout << (isFirstCharUppercase(inputString) ? "First character is in uppercase" : "First character is not in uppercase") << endl;
                break;

            case 3:
                reverseString(inputString);
                cout << "Reversed string: " << inputString << endl;
                break;

            case 4:
                displayAddresses(inputString);
                break;

            case 5:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}
// question 6
#include <iostream>

using namespace std;

class Triangle {
private:
    double base;
    double height;

public:
    // Constructor
    Triangle(double b, double h) : base(b), height(h) {}

    // Function to calculate the area of the triangle (base * height / 2)
    double calculateArea() {
        return 0.5 * base * height;
    }

    // Overloaded function to calculate the area of the triangle using a different parameter type (newBase)
    double calculateArea(double newBase) {
        return 0.5 * newBase * height;
    }

    // Overloaded function to calculate the area of the triangle using a different parameter type (newHeight)
    double calculateArea(int newHeight) {
        return 0.5 * base * newHeight;
    }
};

int main() {
    // Creating a Triangle object with base 4.0 and height 6.0
    Triangle myTriangle(4.0, 6.0);

    // Calculating and displaying the area using the original base and height
    cout << "Area of the triangle: " << myTriangle.calculateArea() << endl;

    // Calculating and displaying the area using a new base (8.0)
    cout << "Area with a new base: " << myTriangle.calculateArea(8.0) << endl;

    // Calculating and displaying the area using a new height (10)
    cout << "Area with a new height: " << myTriangle.calculateArea(10) << endl;

    return 0;
}
// question 7
#include <iostream>

using namespace std;

template <typename T>
class TwoDim {
protected:
    T x, y;

public:
    // Default constructor
    TwoDim() : x(0), y(0) {}

    // Parameterized constructor
    TwoDim(T xVal, T yVal) : x(xVal), y(yVal) {}

    // Function to print coordinates
    void print() const {
        cout << "Coordinates: (" << x << ", " << y << ")" << endl;
    }
};

// Subclass ThreeDim inheriting from TwoDim
template <typename T>
class ThreeDim : public TwoDim<T> {
private:
    T z;

public:
    // Default constructor
    ThreeDim() : TwoDim<T>(), z(0) {}

    // Parameterized constructor
    ThreeDim(T xVal, T yVal, T zVal) : TwoDim<T>(xVal, yVal), z(zVal) {}

    // Function to print coordinates
    void print() const {
        cout << "Coordinates: (" << this->x << ", " << this->y << ", " << z << ")" << endl;
    }
};

int main() {
    // Using TwoDim with integers
    TwoDim<int> point2D(3, 5);
    point2D.print();

    // Using ThreeDim with doubles
    ThreeDim<double> point3D(1.2, 4.5, 6.7);
    point3D.print();

    // Runtime polymorphism
    TwoDim<double>* ptr = &point3D;
    ptr->print();

    return 0;
}*/
//question 8 
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    // Create and write to input file
    ofstream createInputFile("input.txt");
    createInputFile << "This is a sample." << endl;
    createInputFile.close();

    // Input file
    ifstream inputFile("input.txt");

    // Output file
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Error: Could not open output file." << endl;
        return 1;
    }

    char ch;
    int charCount = 0;

    while (inputFile.get(ch)) {
        if (!isspace(ch)) {  // Exclude whitespace characters (newline, space, etc.)
            outputFile.put(ch);
            charCount++;
        }
    }

    // Close files
    inputFile.close();
    outputFile.close();

    cout << "Number of visible characters copied: " << charCount << endl;

    return 0;
}














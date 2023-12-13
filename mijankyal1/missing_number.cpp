#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    // Calculate the sum of the first n natural numbers
    int sum = ((n + 1) * (n + 2)) / 2;

    // Calculate the actual sum of the elements in the array
    int actualSum = 0;
    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
    }

    // Calculate the missing number
    return sum - actualSum;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    if (n < 1) {
        cout << "Invalid input. 'n' should be a positive integer." << endl;
        return 1;
    }

    int arr[20]; // You can set a reasonable upper limit for the array size

    if (n > 20) {
        cout << "Array size too large. Please reduce 'n'." << endl;
        return 1;
    }

    cout << "Enter " << n << " numbers from 1 to " << n + 1 << " with one number missing:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int missingNumber = findMissingNumber(arr, n);
    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}
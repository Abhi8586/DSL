#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    if(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);
        else
            return binarySearch(arr, mid + 1, high, key);
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 40;

    int result = binarySearch(arr, 0, n - 1, key);

    if(result == -1)
        cout << "Element not found";
    else
        cout << "Element found at position: " << result + 1;

    return 0;
}

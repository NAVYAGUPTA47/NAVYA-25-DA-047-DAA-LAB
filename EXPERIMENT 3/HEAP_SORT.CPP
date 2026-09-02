//NAVYA GUPTA 25/DA/047
#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {

    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check right child
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not the root
    if (largest != i) {

        swap(arr[i], arr[largest]);

        // Heapify the affected subtree
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {

    int n = arr.size();

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {

        // Move largest element to the end
        swap(arr[0], arr[i]);

        // Restore Max Heap
        heapify(arr, i, 0);
    }
}

int main() {

    cout<<"NAVYA GUPTA ROLL NO 25/DA/047\n";
    cout<<"HEAP SORT\n";
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr;

    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++) {

        int x;
        cin >> x;

        arr.push_back(x);
    }

    heapSort(arr);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

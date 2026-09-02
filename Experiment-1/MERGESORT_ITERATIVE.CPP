#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {

    vector<int> temp;

    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high) {

        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Remaining left elements
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Remaining right elements
    while (j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy back
    for (int k = 0; k < temp.size(); k++) {
        arr[low + k] = temp[k];
    }
}


void mergeSort(vector<int>& arr) {

    int n = arr.size();

    // Current size of subarrays
    for (int size = 1; size < n; size = size * 2) {

        // Pick starting point of each pair
        for (int low = 0; low < n - 1; low += 2 * size) {

            int mid = min(low + size - 1, n - 1);

            int high = min(low + 2 * size - 1, n - 1);

            if (mid < high) {
                merge(arr, low, mid, high);
            }
        }
    }
}


int main() {

    cout<<"NAVYA GUPTA ROLL NO 25/DA/047\n";
    cout<<"MERGE SORT USING ITERATIVE APPROACH\n";

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

    mergeSort(arr);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

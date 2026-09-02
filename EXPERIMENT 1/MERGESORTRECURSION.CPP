//NAVYA GUPTA ROLL NO 25/DA/047
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

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        arr[low + k] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {

    if (low >= high) {
        return;
    }

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main() {

    cout<<"NAVYA GUPTA ROLL NO 25/DA/047\n";
    cout<<"MERGE SORT USING RECURSIVE APPROACH\n";
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr;       // Empty vector

    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        arr.push_back(k);  // Add element
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
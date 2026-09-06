//NAVYA GUPTA 25/DA/047
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cout<<"NAVYA GUPTA ROLL NO 25/DA/047\n";
    cout<<"FRACTIONAL KNAPSACK USING GREEDY APPROACH\n";
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[n], value[n];
    double ratio[n];

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
        ratio[i] = (double)value[i] / weight[i];
    }

    cout << "Enter capacity: ";
    cin >> capacity;

    // Sort according to value/weight ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(weight[i], weight[j]);
                swap(value[i], value[j]);
            }
        }
    }

    double profit = 0;

    for (int i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            capacity -= weight[i];
            profit += value[i];
        }
        else {
            profit += ratio[i] * capacity;
            break;
        }
    }

    cout << "Maximum profit = " << profit << endl;

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countingSort(int arr[], int n, int exp) {
    int output[100];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    srand(time(0));
    const int SIZE = 15;
    int transactions[SIZE];
    for (int i = 0; i < SIZE; i++)
        transactions[i] = rand() % 10000;

    cout << "Original Transaction Amounts:\n";
    for (int i = 0; i < SIZE; i++)
        cout << transactions[i] << " ";
    cout << "\n\n";

    radixSort(transactions, SIZE);

    cout << "Sorted Transaction Amounts (Ascending):\n";
    for (int i = 0; i < SIZE; i++)
        cout << transactions[i] << " ";
    cout << endl;

    return 0;
}

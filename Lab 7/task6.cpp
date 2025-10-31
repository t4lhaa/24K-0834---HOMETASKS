#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;
    int id;
    double salary;
};

void merge(Employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee* L = new Employee[n1];
    Employee* R = new Employee[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].salary >= R[j].salary) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void displayTop3(Employee arr[], int n) {
    cout << "\nTop 3 Highest Paid Employees:\n";
    cout << "-------------------------------------------\n";
    for (int i = 0; i < 3 && i < n; i++) {
        cout << "Name: " << arr[i].name << endl;
        cout << "ID: " << arr[i].id << endl;
        cout << "Salary: Rs." << arr[i].salary << endl;
        cout << "-------------------------------------------\n";
    }
}

int main() {
    Employee employees[12] = {
        {"Ahmed Khan", 101, 85000},
        {"Fatima Ali", 102, 72000},
        {"Hassan Raza", 103, 98000},
        {"Ayesha Malik", 104, 91000},
        {"Bilal Ahmed", 105, 64000},
        {"Zainab Tariq", 106, 87000},
        {"Usman Iqbal", 107, 59000},
        {"Maryam Noor", 108, 99000},
        {"Imran Shah", 109, 56000},
        {"Sana Javed", 110, 88000},
        {"Hamza Saeed", 111, 93000},
        {"Laiba Nadeem", 112, 70000}
    };

    int n = 12;

    cout << "Original Employee Records:\n";
    cout << "-------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << employees[i].name << endl;
        cout << "ID: " << employees[i].id << endl;
        cout << "Salary: Rs." << employees[i].salary << endl;
        cout << "-------------------------------------------\n";
    }

    mergeSort(employees, 0, n - 1);
    displayTop3(employees, n);

    return 0;
}

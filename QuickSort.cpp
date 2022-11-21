#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

using namespace std;

/*
Zaimplementować metodę sortowania szybkiego (QuickSort).
Zaimplementować ponadto jedną z klasycznych metod sortowania (sortowanie przez wybór, wstawianie lub sortowanie bąbelkowe)
i porównać czas działania obu algorytmów dla tablic danych o różnej długości.
*/

const int n = 50000; // liczba danych do posortowania
const int bottom = 0; // od
const int top = 100000000; // do

int divide(int *&arr, int first, int last) {

    int pivotElement = arr[last];
    int i = first-1;

    for (int j=first; j<last; j++) {
        if (arr[j] <= pivotElement) {
            i++;
            // zamien T[i] z T[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int pivot = i+1;
    // zamien T[pivot] z T[first]
    arr[last] = arr[pivot];
    arr[pivot] = pivotElement;

    return pivot;
}

void quicksort(int *&arr, int first, int last) {

    int pivot = divide(arr, first, last);

    if (pivot-1 > first) {
        quicksort(arr, first, pivot-1);
    }
    if (pivot+1 < last) {
        quicksort(arr, pivot+1, last);
    }
}

void bubblesort(int *&arr) {

    for (int i=0; i<n-1; i++) {
        for (int j=0; j<=n-2-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int *arr, string title) {

    cout << title << endl;
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // dane do sortowania
    srand (time(NULL));
    int *arr1 = new int [n];
    for (int i=0; i<n; i++) {
        arr1[i] = bottom + (rand() % (top - bottom + 1));
    }
    int *arr2 = new int [n];
    for (int i=0; i<n; i++) {
        arr2[i] = bottom + (rand() % (top - bottom + 1));
    }

    // printArray(arr1, "Przed quicksortem");
    auto qs_start = chrono::high_resolution_clock::now();
    quicksort(arr1, 0, n-1);
    auto qs_end = chrono::high_resolution_clock::now();
    // printArray(arr1, "Po quicksorcie");

    // printArray(arr2, "Przed bombelkowym");
    auto bs_start = chrono::high_resolution_clock::now();
    bubblesort(arr2);
    auto bs_end = chrono::high_resolution_clock::now();
    // printArray(arr2, "Po bombelkowym");

    double bs_time = chrono::duration_cast<chrono::nanoseconds>(bs_end - bs_start).count() * 1e-9;
    double qs_time = chrono::duration_cast<chrono::nanoseconds>(qs_end - qs_start).count() * 1e-9;

    cout << "Quicksort zabral " << qs_time << " sekund." << endl;
    cout << "Bubblesort zabral " << bs_time << " sekund." << endl;

    cout << "Bubblesort zabral " << bs_time / qs_time << " razy wiecej." << endl;

    return 0;
}

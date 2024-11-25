#ifndef SORTING_H
#define SORTING_H

#include <functional>

// Merge Sort with custom comparator
template <typename T>
void merge_sort(T arr[], int left, int right, std::function<bool(const T &, const T &)> comp)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid, comp);
        merge_sort(arr, mid + 1, right, comp);

        merge(arr, left, mid, right, comp);
    }
}

template <typename T>
void merge(T arr[], int left, int mid, int right, std::function<bool(const T&, const T&)> comp) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (comp(L[i], R[j])) {
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
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free temporary arrays
    delete[] L;
    delete[] R;
}

#endif
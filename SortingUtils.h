#ifndef SORTING_UTILS_H
#define SORTING_UTILS_H

#include <vector>

namespace SortingUtils {

// 冒泡排序
template <typename T>
void bubble_sort(std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 快速排序
template <typename T>
void quick_sort(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        T pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[right]);
        quick_sort(arr, left, i);
        quick_sort(arr, i + 2, right);
    }
}

} // namespace SortingUtils

#endif // SORTING_UTILS_H
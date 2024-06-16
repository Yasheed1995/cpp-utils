#ifndef SEARCHING_UTILS_H
#define SEARCHING_UTILS_H

#include <vector>

namespace SearchingUtils {

// 二分查找
template <typename T>
int binary_search(const std::vector<T>& arr, T target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // 如果沒有找到目標值
}

} // namespace SearchingUtils

#endif // SEARCHING_UTILS_H
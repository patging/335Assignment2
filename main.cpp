// Patrick Ging

#include "HalfHeapSort.hpp"
#include "HalfSelectionSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "MedianOfMediansMethod.hpp"
#include "MergeSort.hpp"
#include "QuickSelect.hpp"
#include "StandardSort.hpp"
#include "WorstCaseQuickSelect.hpp"

#include <iostream>
#include <chrono>

int main() { 

    // std::vector<int> nums = { 2, 1, 3 , -100, 1002039, 100};
    // int d = 5;

    // std::cout << quickSelect(nums, d) << std::endl;

    std::vector<int> nums;
    worstCaseQuickSelect(nums);
    int duration = 7000;

    // for(int i = 0; i < 20000; i++) {
    //     nums.push_back(i);
    // }

    auto start = std::chrono::steady_clock::now();

    halfHeapSort(nums, duration);

    auto end = std::chrono::steady_clock::now();

    auto diff = end - start;

    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count() << std::endl;
    return 0;
}
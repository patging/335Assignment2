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

int main() { 

    std::vector<int> nums = { 2, 1, 3 , -100, 1002039, 100};
    int d = 0;

    std::cout << quickSelect(nums, d) << std::endl;

    return 0;
}
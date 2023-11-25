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

    std::vector<int> v = {2, 3, 4, 1, 5, 6, 7, 1000};
    int d = 10;
    std::cout << "Median" << halfHeapSort(v,d) << std::endl;
    // for (int i = 0; i < v.size(); i++) {
    //     std::cout << v[i] << " ";
    // }

    return 0;
}
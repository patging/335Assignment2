#include "QuickSelect.hpp"

std::vector<int>::iterator hoarePartition ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high ) {

    int pivot = *high;

    std::vector<int>::iterator i = low - 1;
    std::vector<int>::iterator j = high + 1;

    while (true) {
        /*
            find values that are not abiding to their side and swap them
            until they reach the same pivot value
        */
        while(*j < pivot) {
            j = j + 1;
        }
        while (pivot > *i) {
            i = i - 1;
        }

        if (i == j) {
            return i;
        }

        std::swap(*i, *j);
    }

}

std::vector<int>::iterator medianOfThree(std::vector<int>& nums) {
    std::vector<int> tmp = {}
} 


int quickSelect ( std::vector<int>& nums, int& duration ) {

    auto median = medianOfThree(nums); // im just going to encapsulate this.... :( 

}

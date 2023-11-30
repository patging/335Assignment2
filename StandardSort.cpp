#include "StandardSort.hpp"

#include <vector>
#include <algorithm>

/*
    calls std::sort and returns the middle element
*/
int standardSort ( std::vector<int>& nums, int& duration ) {
    std::sort(nums.begin(), nums.end());

    return nums[ (nums.size() - (1 - nums.size() % 2) ) / 2 ];
}
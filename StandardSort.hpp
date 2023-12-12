#include <vector>
#include <algorithm>
#include <chrono>
/*
    calls std::sort and returns the middle element
*/
int standardSort ( std::vector<int>& nums, int& duration ) {

    auto s = std::chrono::steady_clock::now();    

    std::sort(nums.begin(), nums.end());

    auto end = std::chrono::steady_clock::now();

    auto diff = end - s;

    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count();

    return nums[ (nums.size() - (1 - nums.size() % 2) ) / 2 ];
}
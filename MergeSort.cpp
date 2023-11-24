#include "MergeSort.hpp"

#include <algorithm>

/*
    conducts the merge sort and returns the median
*/
int mergeSort ( std::vector<int>& nums, int& duration ) {
    if (nums.size() == 1) {
        return nums[0];
    }

    std::vector<int> l;
    std::copy(nums.begin(), nums.begin() + (nums.size() / 2), l.begin());
    std::vector<int> r;
    std::copy(nums.begin() + (nums.size() / 2), nums.end(), r.begin());

    int d = duration;
    mergeSort(l, d);
    mergeSort(r, d);
    
    int i = 0;
    while (l.size() != 0 || r.size() != 0) {
        if (l.size() == 0) {
            nums[i] = r.front();
            r.erase(r.begin());

        } else if (r.size() == 0) {
            nums[i] = l.front();
            l.erase(l.begin());
        } else {
            // add the smaller element to our new arr
            if ( l.front() < r.front() ) {
                nums[i] = l.front();
                l.erase(l.begin());
            } else {
                nums[i] = r.front();
                r.erase(r.begin());
            }
        }
        i += 1;
    }

    return 1;
    //return nums[ (nums.size() - (1 - nums.size() % 2) ) / 2 ];
}
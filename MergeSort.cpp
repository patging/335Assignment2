#include "MergeSort.hpp"

#include <algorithm>

/*
    conducts the merge sort and returns the median
*/
int mergeSort ( std::vector<int>& nums, int& duration ) {
    if (nums.size() == 1) {
        return nums[0];
    } else if (nums.size() == 0) {
        return -1;
    }

    std::vector<int> l;
    for (int i = 0; i < nums.size() / 2; i++)
        l.push_back(nums[i]);
    
    std::vector<int> r;
    for (int i = nums.size() / 2; i < nums.size(); i++)
        r.push_back(nums[i]);

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

    return nums[ (nums.size() - (1 - nums.size() % 2) ) / 2 ];
}
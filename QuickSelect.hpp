#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int>::iterator hoarePartition ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high , int pivot) {

    // int pivot = *high;

    std::vector<int>::iterator i = low - 1;
    std::vector<int>::iterator j = high + 1;

    while (true) {
        /*
            find values that are not abiding to their side and swap them
            until they reach the same pivot value
        */
        do {
            i = i + 1;
            // std::cout << *i << std::endl;

        } while(*i < pivot);
        do {
            j = j - 1;
        } while (*j > pivot || i >= nums.end());

        // std::cout << *i << " " << *j << std::endl;


        if (i >= j) {
            return i;
        }

        std::iter_swap(i, j);
    }

    return i;

}

std::vector<int>::iterator medianOfThree(std::vector<int>::iterator a, std::vector<int>::iterator c) {
    std::vector<int>::iterator b = a + (((c + 1 - a) - (1 - (c + 1 - a) % 2) ) / 2);

    // std::cout << *a << " " << *b << " " << *c << std::endl;

    // using XOR to say that if 
    // a number is greater than one or the other
    // then it assuredly is the median
    if ( ((*a > *b) ^ (*a > *c)) || (*a == *c) )
        return a;
    
    if ( ((*b > *a) ^ (*b > *c)) || (*b == *a) || (*b == *c) )
        return b;
    
    return c;

} 

/*
    using the quickselect and the median of three algorithm for faster timing to get the
    
    duration smallest value
*/
int quickSelect ( std::vector<int>& nums, int& duration ) {

    /*
        to do rewrite this for recursive
    */

    int l = 0;
    int r = nums.size() - 1;

    std::vector<int>::iterator pivot;

    // have to write this iteratively :(     

    while ( l < r ) {

        pivot = medianOfThree( nums.begin() + l ,nums.begin() + r);
        // std::cout << "l : " << l << " r " << r << std::endl;

        // std::cout << *pivot << std::endl;
        pivot = hoarePartition(nums, nums.begin() + l, nums.begin() + r, *pivot);

        // debug print
        // for (int i = 0; i < nums.size(); i++) {
        //     std::cout << nums[i] << " ";
        // }
        // std::cout << *pivot << std::endl;
        // std::cout << std::endl;


        if (duration == (pivot - nums.begin())) {
            return *pivot;
        } else if ( duration < (pivot - nums.begin()) ) {
            r = pivot - nums.begin() - 1;
        } else {
            l = pivot - nums.begin() + 1;
        }

    }

    return nums[l]; // meaning something went terribly wrong ( i can't think of why, but this is for the compiler tbh )
}

#include "QuickSelect.hpp"

#include <algorithm>
#include <iostream>

std::vector<int>::iterator hoarePartition ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high , int pivot) {

    // int pivot = *high;

    std::vector<int>::iterator i = nums.begin() - 1;
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
            return j;
        }

        std::iter_swap(i, j);
    }

}

std::vector<int>::iterator medianOfThree(std::vector<int>::iterator a, std::vector<int>::iterator c) {
    std::vector<int>::iterator b = a + (((c + 1 - a) - (1 - (c + 1 - a) % 2) ) / 2);

    // std::cout << *a << " " << *b << " " << *c << std::endl;

    // using XOR to say that if 
    // a number is greater than one or the other
    // then it assuredly is the median
    if ( ((*a > *b) ^ (*a > *c)) || (*a == *c))
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

    std::vector<int>::iterator l = nums.begin();
    std::vector<int>::iterator r = nums.end() - 1;

    std::vector<int>::iterator pivot; // im just going to encapsulate this.... :( 

    while ( l < r ) {

        pivot = medianOfThree( l , r);
        std::cout << "l : " << *l << " r " << *r << std::endl;

        // std::cout << *pivot << std::endl;
        pivot = hoarePartition(nums, l, r, *pivot);

        // debug print
        for (int i = 0; i < nums.size(); i++) {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;


        if (duration == (pivot - nums.begin())) {
            return *pivot;
        } else if ( duration < (pivot - nums.begin()) ) {
            r = pivot - 1;
        } else {
            l = pivot + 1;
        }

    }

    return nums.at(*l); // meaning something went terribly wrong ( i can't think of why, but this is for the compiler tbh )
}

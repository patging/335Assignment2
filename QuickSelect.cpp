#include "QuickSelect.hpp"

#include <algorithm>
#include <iostream>

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

std::vector<int>::iterator medianOfThree(std::vector<int>::iterator a, std::vector<int>::iterator c) {
    std::vector<int>::iterator b = a + (((c + 1 - a) - (1 - (c + 1 - a) % 2) ) / 2);

    std::cout << *a << " " << *b << " " << *c << std::endl;

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
    std::vector<int>::iterator r = nums.end();

    std::vector<int>::iterator median = medianOfThree( l , r - 1); // im just going to encapsulate this.... :( 

    // while ( l < r ) {

    // }
    return 6;

}

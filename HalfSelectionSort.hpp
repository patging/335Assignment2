#include <iostream>
#include <chrono>
/*
    iterates through the vector, finds the smallest element,
    until it finds the median. will return the median and half sort the vector

    will abort for sizes greater than 50,000
*/
int halfSelectionSort ( std::vector<int>& nums, int& duration ) {

    auto s = std::chrono::steady_clock::now();

    // Checking for invalid sizes
    if ( nums.size() > 50000 ) {
        throw new std::runtime_error("Error: Vector size is greater than 50,000.");
    } else if (nums.size() <= 0) {
        throw new std::runtime_error("Error: Empty Vector");
    } else if (nums.size() == 1) {
        return nums[0];
    }

    // running partial
    auto start = nums.begin();
    // to find the median, you only have to run the 
    // loop for half the size
    for ( int i = 0; i < (nums.size() + 1) / 2 ; i++ ) {
        // locating the min value
        std::vector<int>::iterator min = start; // assuming first value is the min
        for ( auto p = start; p != nums.end(); p++ ) {
            if ( *p < *min ) {
                min = p;
            }
        }
        // then appending it to the from of the array
        // and updating the start pointer
        std::iter_swap(nums.begin() + i , min);
        start = nums.begin() + i + 1;
    }

    auto end = std::chrono::steady_clock::now();

    auto diff = end - s;

    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count();

    // returning the median
    return *(start-1);
}
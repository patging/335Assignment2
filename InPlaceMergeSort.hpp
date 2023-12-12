#include <vector>
#include <algorithm>

void inPlaceMerge( std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (end - begin <= 1) {
        return;
    }

    inPlaceMerge(begin, begin + ((end - begin) / 2)); // merge the left half
    inPlaceMerge(begin + ((end - begin) / 2), end); // merging the right half

    // conducting the merge using std:: in place merge
    std::inplace_merge(begin, begin + ((end - begin) / 2) , end );

}

int inPlaceMergeSort ( std::vector<int>& nums, int& duration ) {
    inPlaceMerge(nums.begin(), nums.end());
    
    return nums[ (nums.size() - (1 - nums.size() % 2) ) / 2 ];
}
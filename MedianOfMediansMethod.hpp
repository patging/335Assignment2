#include <vector>

int medianOfMediansMethod ( std::vector<int>& nums, int& duration );
int medianOfMedians ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high );
// returns the median of medians of all elements contained between high and low, inclusive.
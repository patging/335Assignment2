#include <vector>

void worstCaseQuickSelect (std::vector<int>& nums) {

    for (int i = 0; i < 20000; i++) {
        if ( i % 2 != 0 ) {
            nums.insert(nums.begin(), i);
        } else {
            nums.push_back(i);
        }
    }
}
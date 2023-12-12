
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>

/*
    heapify for the max heap
*/
void heapify(std::vector<int>& heap, std::vector<int>::size_type loc) {
    int left = 2 * loc + 1;
    int right = 2 * loc + 2;

    int largest = loc;

    // checking if there's a node that is out of place in this
    // subtree and changing it on largest
    if (left < heap.size() && heap[left] > heap[loc]) {
        largest = left;
    } else if (right < heap.size() && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != loc) {
        // if there's a revision we need to make
        // swap and call down on the subtree we have an issue with
        std::swap(heap[loc], heap[largest]); // much faster than iter_swap
        heapify(heap, largest);
    }

}

// parameter "hole" is the index of the hole.
// percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself 
// may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
// percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
void percDown ( std::vector<int>& heap, std::vector<int>::size_type hole ) {
    if (heap.size() != 0) {
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(heap,0);
    }
}

void buildHeap ( std::vector<int>& heap) {
    // you don't need to do the entire heap because the bottom nodes have no
    // child nodes and are technically are sorted in their own subtree.
    for (int i = heap.size() / 2; i >= 0; i--) {
        heapify(heap, i);
    }   
}

/*
    conducts a heap sort and then returns the median
*/
int halfHeapSort ( std::vector<int>& nums, int& duration ) {
    auto s = std::chrono::steady_clock::now();    
    
    buildHeap(nums);

    int epochs = nums.size();

    for (int i = 0; i < ((epochs - (1 - epochs % 2) ) / 2); i++) {
        // doing a partial heap sort until the item right before the median
        nums.erase(nums.begin()); // popping the top item
        percDown(nums, 0);
    }

    auto end = std::chrono::steady_clock::now();

    auto diff = end - s;

    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count();

    return nums[0]; // in theory should be the median
}
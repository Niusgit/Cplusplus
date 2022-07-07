#include <assert.h>

#include <iostream>
#include <vector>

int removeElement(std::vector<int> nums, int val) {
    int startIndex = -1, currIndex = 0;

    while (currIndex < nums.size()) {
        if (nums[currIndex] != val) {
            currIndex++;
        } else {
            startIndex = currIndex;
            break;
        }
    }

    std::cout << "startIndex: " << startIndex << ", currIndex: " << currIndex << std::endl;

    while (currIndex < nums.size()) {
        if (nums[currIndex] == val) {
            currIndex++;
            continue;
        }
        nums[startIndex] = nums[currIndex++];
        startIndex++;
    }

    if (startIndex < 0) startIndex = nums.size();
    else nums.resize(startIndex);
    
    return startIndex;
}

int main() {
    std::vector<int> testVec1 = {1, 2, 1, 3};
    std::vector<int> testVec2 = {1, 1, 1};
    std::vector<int> testVec3 = {};

    assert(removeElement(testVec1, 1) == 2);
    assert(removeElement(testVec1, 2) == 3);
    assert(removeElement(testVec1, 4) == 4);
    assert(removeElement(testVec2, 1) == 0);
    assert(removeElement(testVec3, 1) == 0);

    return 0;
}
#include <assert.h>

#include <vector>

int binarySearch(std::vector<int> &nums, int start, int end, int target) {
    if (start > end) {
        if (start >= nums.size()) return nums.size();
        if (nums[start] > target) return start;
        else return start + 1;
    }
    int mid = (start + end) / 2;

    if (nums[mid] == target) return mid;
    else if (nums[mid] > target) {
        return binarySearch(nums, start, mid - 1, target);
    } else {
        return binarySearch(nums, mid + 1, end, target);
    }
}

int searchInsert(std::vector<int>& nums, int target) {
    return binarySearch(nums, 0, nums.size() - 1, target);
}

int main() {
    std::vector<int> testVec = { 1, 2, 4, 5, 7 };
    std::vector<int> testVec2 = { };

    assert(searchInsert(testVec, 2) == 1);
    assert(searchInsert(testVec, 7) == 4);
    assert(searchInsert(testVec, 3) == 2);
    assert(searchInsert(testVec, 0) == 0);
    assert(searchInsert(testVec, 10) == 5);
    assert(searchInsert(testVec2, 2) == 0);

    return 0;
}
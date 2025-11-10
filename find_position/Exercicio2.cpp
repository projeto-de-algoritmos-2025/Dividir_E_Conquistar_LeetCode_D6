#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }

private:
    int findFirst(const std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int firstPos = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2; 

            if (nums[mid] == target) {
                firstPos = mid;
                high = mid - 1; 
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return firstPos;
    }

    int findLast(const std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int lastPos = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                lastPos = mid;
                low = mid + 1; 
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return lastPos;
    }
};
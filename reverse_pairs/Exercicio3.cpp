#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int mergeAndCount(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1; 

        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        
        vector<int> temp;
        int p1 = left;    
        int p2 = mid + 1; 

        while (p1 <= mid && p2 <= right) {
            if (nums[p1] <= nums[p2]) {
                temp.push_back(nums[p1++]);
            } else {
                temp.push_back(nums[p2++]);
            }
        }

        while (p1 <= mid) {
            temp.push_back(nums[p1++]);
        }

        while (p2 <= right) {
            temp.push_back(nums[p2++]);
        }

        for (int i = 0; i < temp.size(); i++) {
            nums[left + i] = temp[i];
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return 0;
        }

        int mid = left + (right - left) / 2;

        int leftPairs = mergeSort(nums, left, mid);
        int rightPairs = mergeSort(nums, mid + 1, right);

        int crossPairs = mergeAndCount(nums, left, mid, right);

        return leftPairs + rightPairs + crossPairs;
    }

public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
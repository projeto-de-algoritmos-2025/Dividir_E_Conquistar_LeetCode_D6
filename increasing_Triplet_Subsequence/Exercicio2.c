#include <vector>
#include <limits>
#include <iostream>

class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        
        int primeiro = std::numeric_limits<int>::max();
        int segundo = std::numeric_limits<int>::max();

        for (int num : nums) {
            
            if (num <= primeiro) {
                primeiro = num;
            } 
            else if (num <= segundo) {
                segundo = num;
            } 
            else { 
                return true;
            }
        }
        
        return false;
    }
};
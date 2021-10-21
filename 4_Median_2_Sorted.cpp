#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //compare medians
    //ex [1, 3, 4] and [2, 6, 7]
    //3 vs 6, 3 smaller than 6, so we ignore everything to the left
    //of 3 in arr1 and everything to the right of 6 in arr 2
    //keep doing this until the total length of the remaining is 1 or 2
    



}

double find_median(vector<int> nums) {
    if (nums.size() % 2 == 0) {
        return (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2;
    } 
    else {
        return nums[nums.size() / 2];
    }
}

int main() {
    
    return 0;
}
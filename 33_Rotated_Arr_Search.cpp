#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    //find index of smallest element using binary search
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[right]) left = mid + 1; //not in correct segment
        else right = mid; //already in correct segment
    }

    //left == right here, where left == index of smallest element
    if (target == nums[left]) return left;

    //figure out which range target is in
    if (target > nums[left] && target <= nums[nums.size() - 1]) {
        right = nums.size() - 1;
    }
    else {
        left = 0;
    }

    //binary search
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        else if (target < nums[mid]) right = mid - 1;
        else if (target > nums[mid]) left = mid + 1;
    }

    return -1;
}

int main() {
    // vector<int> n = {5,6,7,0,1,2,4};
    vector<vector<int>> nums = {
        {5,6,7,0,1,2,4},
        {4,5,6,7,0,1,2},
        {4,5,6,7,0,1,2},
        {1},
        {1,2,3,4,5,6,7},
        {2,3,4,5,6,7,1},
        {1,3}
    };

    vector<int> target = {
        2, 
        0, 
        3, 
        0,
        4,
        1,
        3
    };

    vector<int> ans = {
        5, 
        4,
        -1,
        -1,
        3,
        6,
        1
    };

    for (int i = 0; i < nums.size(); ++i) {
        int curr_ans = search(nums[i], target[i]);
        if (curr_ans != ans[i]) {
            cout << i << ", " << ans[i] << ", " << curr_ans << endl;
        }
    }
    return 0;
}
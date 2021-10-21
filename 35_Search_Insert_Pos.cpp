#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int idx = left + (right - left) / 2;

    while (left <= right) {
        if (left == right) {
            if (target == nums[idx]) return idx;
            else {
                if (target < nums[idx]) {
                    if (idx - 1 < 0) return 0;
                    else return idx;
                }
                else if (target > nums[idx]) {
                    return idx + 1;
                }
            }
        }
        if (target == nums[idx]) return idx;
        else if (target < nums[idx]) {
            right = idx - 1;
            idx = left + (right - left) / 2;
        }
        else if (target > nums[idx]) {
            left = idx + 1;
            idx = left + (right - left) / 2;
        }
    }

    return idx;
}
// //modified binary search
// int binary_search(vector<int> nums, int target) {

// }



int main() {
    vector<vector<int>> nums = {
        {1, 3, 5, 6},
        {1, 3, 5, 6},
        {1, 3, 5, 6},
        {1, 3, 5, 6},
        {1},
        {1, 3, 5, 7, 9},
        {1, 3}
    };

    vector<int> target = {
        5,
        2,
        7,
        0,
        0,
        4,
        2
    };

    vector<int> ans = {
        2,
        1,
        4,
        0,
        0,
        2,
        1
    };

    for (int i = 0; i < nums.size(); ++i) {
        int curr_ans = searchInsert(nums[i], target[i]);
        if (curr_ans != ans[i]) {
            cout << i << ", " << curr_ans << ", " << ans[i] << endl;
        }
    }
    return 0;
}
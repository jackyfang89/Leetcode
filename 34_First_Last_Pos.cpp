#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> nums, int target, int left, int right) {
    int idx = left + (right - left) / 2;
    while (left <= right) {
        if (left == right) {
            if (nums[right] == target) return right;
            else return -1;
        }
        if (nums[idx] == target) return idx;
        else if (target < nums[idx]) {
            right = idx - 1;
            idx = left + (right - left) / 2;
        }
        else {
            left = idx + 1;
            idx = left + (right - left) / 2;
        }
    }

    return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int end = nums.size() - 1;
    if (nums.size() == 0) return vector<int>{-1, -1};
    //binary search to find the index first
    int orig_idx = binary_search(nums, target, 0, end);
    if (orig_idx == -1) return vector<int>{-1, -1};

    // cout << "idx: " << orig_idx << endl;
    // cout << "find left" << endl;
    //find left bound
    int left = orig_idx, curr = 0;
    do {
        curr = binary_search(nums, target, 0, left - 1);
        if (curr != -1) left = curr;
    } while (curr != -1);

    // cout << "find right" << endl;

    int right = orig_idx;
    curr = 0;
    do {
        // cout << right << endl;
        curr = binary_search(nums, target, right + 1, end);
        if (curr != -1) right = curr;
    } while (curr != -1);

    return vector<int>{left, right};
}

int main() {
    vector<vector<int>> nums = {
        {5,7,7,8,8,10},
        {5,7,7,8,8,10},
        {},
        {1, 2, 3, 4, 5},
        {2, 2, 2, 2, 2},
        {1, 2, 2, 3, 3}
    };

    vector<int> target = {
        8, 
        6,
        0,
        4,
        2,
        2
    };

    vector<vector<int>> ans = {
        {3, 4},
        {-1, -1},
        {-1, -1},
        {3, 3},
        {0, 4},
        {1, 2}
    };

    for (int i = 0; i < nums.size(); ++i) {
        // cout << i << endl;
        vector<int> curr_ans = searchRange(nums[i], target[i]);
        if (curr_ans[0] != ans[i][0] || curr_ans[1] != ans[i][1]) {
            cout << curr_ans[0] << ", " << curr_ans[1] << " ans: " << ans[i][0] << ", " << ans[i][1] << endl;
        }
    }
    return 0;
}
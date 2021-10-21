#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) {
    //1. look starting from the right and push to left
    //2. find the first non-decreasing subarray
    //3. find the min digit in non-decreasing subarray larger than leftmost digit in subarray
    //4. swap the two
    //5. sort the remaining array in ascending order

    bool has_arrangement = false;
    for (int left = nums.size() - 2; left >= 0; --left) {
        if (nums[left] >= nums[left + 1])  //not found decreasing subarray, keep looking
            continue;

        //found first nondecreasing subarray, do step 3
        has_arrangement = true;
        int min_larger = left + 1;
        for (int i = left + 2; i < nums.size(); ++i) {
            if (nums[i] > nums[left] && nums[i] < nums[min_larger])
                min_larger = i;
        }
        //step 4: swap
        swap(nums[left], nums[min_larger]);
        //step 5: sort remaining array
        sort(nums.begin() + left + 1, nums.end());
        break;
    }

    if (!has_arrangement)
        sort(nums.begin(), nums.end());
}

int main() {
    vector<vector<int>> nums = {
        {1, 2, 3},
        {1, 1, 5},
        {1},
        {3, 2, 1},
        {3, 1, 2},
        {1, 2, 3, 4, 5, 7, 6}, //1234657
        {1, 2, 5, 4, 3, 7, 6}, 
        {4,2,0,2,3,2,0}, //[4,2,0,3,0,2,2] 
        {1, 2}
    };

    for (int i = 0; i < nums.size(); ++i) {
        nextPermutation(nums[i]);
        for (int i: nums[i]) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
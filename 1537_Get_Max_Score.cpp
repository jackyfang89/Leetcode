#include <iostream>
#include <vector>

using namespace std;

int maxSum(vector<int>& nums1, vector<int>& nums2) {
    long long sum1 = 0, sum2 = 0; //sum1 is sum when last added num is in arr1
                            //sum2 is sum when last added num is in arr2
    
    //1. look through both arrays one by one
    //2. increment the pointer pointing to smaller value until they equal or overlap
    //2. if no tunnel, then just continue summing
    //3. if can tunnel, choose maximum between staying and tunneling for 
    //   correct sum (sum1 or sum2)
    
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) { 
        if (nums1[i] < nums2[j]) {
            sum1 += nums1[i];
            ++i;
        }
        else if (nums2[j] < nums1[i]) {
            sum2 += nums2[j];
            ++j;
        }
        else {
            int curr = nums1[i];
            if (sum1 > sum2) {
                sum1 += curr;
                sum2 = sum1;
            }
            else {
                sum2 += curr;
                sum1 = sum2;
            }
            ++i;
            ++j;
        }
    }
    if (i == nums1.size()) {
        while (j < nums2.size()) {
            sum2 += nums2[j];
            ++j;
        }
    }
    else if (j == nums2.size()) {
        while (i < nums1.size()) {
            sum1 += nums1[i];
            ++i;
        }
    }

    int limit = 1000000007;
    long long ans = sum1;
    ans = (sum1 > sum2) ? sum1 : sum2;

    if (ans >= limit) return (ans % limit);
}

int main() {
    vector<vector<int>> num1 = {
        {2, 4, 5, 8, 10},
        {1,3,5,7,9},
        {1,2,3,4,5},
        {1,4,5,8,9,11,19},
        {2,3,4,11,12},
        {1, 2, 3, 4, 5}
    };
    vector<vector<int>> num2 = {
        {4, 6, 8, 9},
        {3,5,100},
        {6,7,8,9,10},
        {2,3,4,11,12},
        {1,4,5,8,9,11,19},
        {1, 2, 3, 4, 5}
    };

    for (int i = 0; i < num1.size(); ++i) {
        cout << maxSum(num1[i], num2[i]) << endl;
    } 

    return 0;
}
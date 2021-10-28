#include <iostream>
#include <vector>

using std::vector;
void print_ans(vector<vector<int>> ans) {
    // std::cout << "attempt: " << std::endl;
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            std::cout << ans[i][j];
            if (j != ans[i].size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << std::endl;
    }
}

bool helper(vector<vector<int>> &ans, vector<int> candidates, int target, int start) {
    // std::cout << "target: " << target << std::endl;
    if (target == 0) { //success
        ans.push_back(vector<int>());
        return true; //success
    }
    
    if (target < candidates[0]) return false; //failed
    
    int has_success = false;
    for (int i = start; i < candidates.size(); ++i) {
        int c = candidates[i];
        // std::cout << c << ", t: " << target << std::endl;
        if (target >= c) {
            if (helper(ans, candidates, target - c, start)) {
                // ++start;
                start = i + 1;
                print_ans(ans);
                // vector<int> curr = ans[ans.size() - 1];
                // curr.insert(curr.begin(), c);
                ans[ans.size() - 1].insert(ans[ans.size() - 1].begin(), c); //only adds for one answer
                has_success = true;
            }
        }
        else break;
    }

    return has_success;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans = vector<vector<int>>();
    int start = 0;

    if (helper(ans, candidates, target, start)) {
        // std::cout << "success!" << std::endl;
        return ans;
    }
    else {
        // std::cout << "fail!" << std::endl;
        return vector<vector<int>>();
    }
}

void compare(vector<vector<int>> attempt, vector<vector<int>> ans) {
    if (attempt.size() != ans.size()) std::cout << "nums rows don't match!" << std::endl;

    bool failed = false;

    for (int i = 0; i < ans.size(); ++i) {
        if (attempt[i].size() != ans[i].size()) std::cout << "nums cols don't match!" << std::endl;
        for (int j = 0; j < ans[i].size(); ++j) {
            if (attempt[i][j] != ans[i][j]) {
                std::cout << "mismatch: " << i << "," << j << std::endl;
                failed = true;
                break;
            }
        }
    }

    if (failed) {
        std::cout << "attempt: " << std::endl;
        print_ans(attempt);
        std::cout << "ans: " << std::endl;
        print_ans(ans);
    }
    
}


int main(){
    vector<vector<int>> cand = {
        // {2,3,6,7},
        // {2,3,5}, 
        {2,3}
        // {2}
    };

    vector<int> target = {
        // 7,
        // 8,
        8
        // 1
    };

    vector<vector<vector<int>>> gold = {
        // {{2,2,3}, {7}},
        // {{2,2,2,2}, {2,3,3}, {3,5}},
        {{2,2,2,2}, {2,3,3}}
        // {}
    };

    for (int i = 0; i < gold.size(); ++i) {
        vector<vector<int>> attempt = combinationSum(cand[i], target[i]);
        // print_ans(attempt);
        // compare(attempt, gold[i]);
    }

    // vector<vector<int>> x = combinationSum(cand[0], target[0]);
    // print_ans(x);

    
    return 0;
}

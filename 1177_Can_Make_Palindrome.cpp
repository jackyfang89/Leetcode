#include <iostream>
#include <vector>
// #include <set>
#include <map>
#include <math.h>
using namespace std;

vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    //naive: look through every substr, get total amt of unique chars = q
    //if q - k > ceiL(n / 2), where n = length of substr, then we can't have palindrome
    vector<bool> ans;

    for (int i = 0; i < queries.size(); ++i) {
        int len = queries[i][1] - queries[i][0] + 1;
        string curr = s.substr(queries[i][0], len);
        
        map<char, int> mp;
        for (int j = 0; j < curr.length(); ++j) {
            if (mp.find(curr[j]) == mp.end()) {
                mp[curr[j]] = 1;
            }
            else {
                ++mp[curr[j]];
            }
        }

        //count the number of chars with odd freqs
        int odd_freqs = 0, k = queries[i][2];
        if (len % 2 != 0) ++k;
        bool has_pal = true;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (it->second % 2 != 0) {
                ++odd_freqs;
                if (odd_freqs > 2*k) {
                    has_pal = false;
                    break;
                }
            }
        }

        ans.push_back(has_pal);
    }
    return ans;
}



int main() {
    vector<string> s = {
        "abcda",
        "lyb",
        "sbcnadgvmjmbunipavmvgpydobypabe"
    };

    vector<vector<vector<int>>> queries = {
        {{3,3,0}, {1,2,0}, {0,3,1}, {0,3,2}, {0,4,1}},
        {{0,1,0}, {2,2,1}},
        {{0,30,3}}
    };

    vector<vector<bool>> ans = {
        {true,false,false,true,true},
        {false,true},
        {false}
    };

    for (int i = 0; i < s.size(); ++i) {
        vector<bool> val = canMakePaliQueries(s[i], queries[i]);
        for (int j = 0; j < val.size(); ++j) {
            if (val[j] != ans[i][j]) {
                cout << "Diff! " << val[j] << ", " << i << ", " << j << endl;
            }
        }
    }
    return 0;
}
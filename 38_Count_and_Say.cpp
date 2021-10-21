#include <iostream>
#include <string>
#include <vector>
using namespace std;

string countAndSay(int n) {
    string s = "1";
    string ans = "1";
    for (int i = 0; i < n; ++i) { //repetitions
        int j = 0; 
        while (j < s.length()) {
            
        }
    }

    return ans;
}

int main() {
    vector<int> n = {
        1, 2, 3, 4
    };

    vector<string> ans = {
        "1", 
        "11",
        "21",
        "1211" 
    };

    for (int i = 0; i < n.size(); ++i) {
        string curr_ans = countAndSay(n[i]);
        if (curr_ans != ans[i]) {
            cout << i << ", " << curr_ans << ", " << ans[i] << endl;
        }
    }

    return 0;
}
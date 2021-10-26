#include <iostream>
#include <string>
#include <vector>
using namespace std;

string countAndSay(int n) {
    string s = "1";
    for (int i = 1; i < n; ++i) {
        int j = 0;
        string temp = "";
        while (j < s.length()) {
            //for the current char, find consec. occurrences.
            char curr = s[j];
            int count = 0;
            while (s[j] == curr) {
                ++count;
                ++j;
            }

            temp += count + '0';
            temp += curr;
        }
        s = temp;
    }

    return s;
}

int main() {
    vector<int> n = {
        1, 2, 3, 4, 5, 6
    };

    vector<string> ans = {
        "1", 
        "11",
        "21",
        "1211",
        "111221",
        "312211"
    };

    for (int i = 0; i < n.size(); ++i) {
        string curr_ans = countAndSay(n[i]);
        if (curr_ans != ans[i]) {
            cout << i << ", " << curr_ans << ", " << ans[i] << endl;
        }
    }

    return 0;
}
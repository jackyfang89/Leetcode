#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')'){
            if (st.size() > 0 && s[st.top()] == '(') { //matched parens
                st.pop(); 
                // curr += 2;
            }
            else {
                st.push(i); //push index of ) that can't be matched
                // if (curr > ans) ans = curr;
                // curr = 0;  //determiend can't match, reset 0
            }
        }
    }
    //at this point, stack only contains indices of parens that can't be matched
    //the substrings between these indices must be valid
    //start looking from the end and get max length
    if (st.size() == 0) return s.length(); //all parens can be matched

    int max = 0;
    int front = st.top() + 1, back = s.length() - 1; //indices of VALID substrings
    while (st.size() >= 0) {
        int curr_length = back - front + 1;
        if (curr_length > max) max = curr_length;
        if (st.size() == 0) return max;
                
        back = front - 2;
        st.pop();
        if (st.size() > 0) front = st.top() + 1;
        else front = 0;
    }

    return max;
}

int main() {
    vector<string> tests = {
        "(()",          //2
        ")",            //0
        ")()())",       //4
        "",             //0
        "((()))()",     //8
        "(",            //0
        ")",            //0
        "))))))",       //0
        "((((",         //0
        "(()))()",      //4
        "()()()()(()()()()()))", //20
        "()(()",         //2
        "()(()()",       //4
        "((())())"       //8
    };

    vector<int> ans = {
        2, 0, 4, 0, 8, 0, 0, 0, 0, 4, 20, 2, 4, 8
    };

    for (int i = 0; i < tests.size(); ++i) {
        // assert(longestValidParentheses(tests[i]) == ans[i]);
        int curr_ans = longestValidParentheses(tests[i]);
        if (curr_ans != ans[i]) {
            cout << "diff! " << tests[i] << ", " << curr_ans << ", " << ans[i] << endl;
        }
        // cout << longestValidParentheses(tests[i]) << endl;
    }
    return 0;
}
//SOLVED

#include <iostream>
#include <vector>
#include <string>
#include <set> 
#include <map>
#include <algorithm>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    //the size of any substring we have to check must necessarily be
    //words.size() * word[0].length(), since the length of all words in vec words
    //is the same, and we need to use every word in words.

    //sanity checks
    if (words.size() == 0 || s.length() == 0) return vector<int>();

    int total_length = words.size() * words[0].length();
    if (total_length > s.length()) return vector<int>();

    int word_length = words[0].length();
    // cout << length << endl;
    // set<string> s;

    //populate frequency of words
    map<string, int> freq;
    for (string word : words) {
        if (freq.find(word) == freq.end()) 
            freq[word] = 1;
        else
            ++freq[word];
    }

    vector<int> ans;

    // for (int i = 0; i <= s.length() - total_length; i += word_length) {
    for (int i = 0; i <= s.length() - total_length; ++i) {
        string curr = s.substr(i, total_length);
        //get frequency of words while checking
        map<string, int> temp;
        bool fail = false;
        for (int j = 0; j < curr.length(); j += word_length) {
            string curr_word = curr.substr(j, word_length);
            if (freq.find(curr_word) == freq.end()){ //curr word in substr not in words vec
                fail = true;
                break;
            } 
            else {
                if (temp.find(curr_word) == freq.end())
                    freq[curr_word] = 1;
                else if (temp[curr_word] == freq[curr_word]) {
                    fail = true;
                    break;
                }
                else 
                    ++temp[curr_word];
            }
        }

        if (!fail) 
            ans.push_back(i);
    }

    return ans;
}

int main() {
    vector<string> strings = {
        "barfoothefoobarman", 
        "wordgoodgoodgoodbestword", 
        "barfoofoobarthefoobarman",
        "lingmindraboofooowingdingbarrwingmonkeypoundcake", 
        "a"
    };

    vector<vector<string>> words = {
        {"foo","bar"}, 
        {"word","good","best","word"}, 
        {"foo", "bar", "the"}, 
        {"fooo","barr","wing","ding","wing"}, 
        {"a", "a"}
    };

    for (int i = 0; i < strings.size(); ++i) {
        vector<int> ans = findSubstring(strings[i], words[i]);
        for (int i: ans) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
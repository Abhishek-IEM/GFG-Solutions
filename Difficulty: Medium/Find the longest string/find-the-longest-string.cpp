class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string ans = "";
    
        for (auto &word : words) {
            if (word.size() == 1 || built.count(word.substr(0, word.size() - 1))) {
                built.insert(word);
                if (word.size() > ans.size()) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};
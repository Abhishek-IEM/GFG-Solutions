class Solution {
public:
    vector<string> possibleWords(vector<int> &arr) {
        vector<string> mapping = {
            "",    // 0
            "",    // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs",// 7
            "tuv", // 8
            "wxyz" // 9
        };

        vector<string> result;
        string cur;
        backtrack(arr, 0, mapping, cur, result);
        return result;
    }

private:
    void backtrack(const vector<int>& arr, int idx, const vector<string>& mapping,
                   string &cur, vector<string> &result) {
        if (idx == (int)arr.size()) {
            if (!cur.empty()) result.push_back(cur); // only push non-empty combos
            return;
        }

        const string &letters = mapping[arr[idx]];
        if (letters.empty()) {
            // skip digits 0 and 1 (no letters) and continue
            backtrack(arr, idx + 1, mapping, cur, result);
            return;
        }

        for (char c : letters) {
            cur.push_back(c);
            backtrack(arr, idx + 1, mapping, cur, result);
            cur.pop_back();
        }
    }
};

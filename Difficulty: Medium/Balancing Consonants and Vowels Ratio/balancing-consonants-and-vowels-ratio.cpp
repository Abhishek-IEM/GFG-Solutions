class Solution {
public:
    int countBalanced(vector<string>& arr) {
        unordered_map<int, int> mp;
        mp[0] = 1;  // Base case: diff 0 seen once
        int vowelCount = 0, consonantCount = 0;
        int result = 0;

        for (const string& word : arr) {
            for (char ch : word) {
                if (isVowel(ch)) vowelCount++;
                else consonantCount++;
            }

            int diff = vowelCount - consonantCount;

            result += mp[diff];
            mp[diff]++;
        }

        return result;
    }

private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};

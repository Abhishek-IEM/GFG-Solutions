class Solution {
  public:
    int vowelCount(string& s) {
        unordered_map<char, int> freq;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        for (char c : s) {
            if (vowels.count(c)) {
                freq[c]++;
            }
        }
        
        int k = freq.size();
        if (k == 0) return 0; // no vowels present
        
        long long selections = 1;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            selections *= it->second;
        }

        
        // Compute k! for permutations
        long long perms = 1;
        for (int i = 1; i <= k; ++i) {
            perms *= i;
        }
        
        return selections * perms;
    }
};
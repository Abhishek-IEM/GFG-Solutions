class Solution {
  public:
    int countStrings(string &s) {
        // code here
        int n = s.length();
        long long total_possible_swaps = (long long)n * (n - 1) / 2;
    
        std::map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        long long swaps_of_identical_chars = 0;
        bool has_duplicate = false;
        
         for (auto const& pair : freq) {
            int count = pair.second;
            if (count > 1) {
                has_duplicate = true;
                // For a character appearing 'count' times, there are countC2 ways to choose 2 of them.
                swaps_of_identical_chars += (long long)count * (count - 1) / 2;
            }
        }
        
         if (!has_duplicate) {
             return static_cast<int>(total_possible_swaps);
        } else {
            long long distinct_strings_from_diff_swaps = total_possible_swaps - swaps_of_identical_chars;
            return static_cast<int>(distinct_strings_from_diff_swaps + 1);
        }
    }
};

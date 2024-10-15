//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Your code here
         unordered_map<int, int> prefixSumFreq;
        int cumulativeSum = 0;
        int count = 0;
        
        prefixSumFreq[0] = 1;
    
        for (int num : arr) {
            cumulativeSum += num;
    
            if (prefixSumFreq.find(cumulativeSum - tar) != prefixSumFreq.end()) {
                count += prefixSumFreq[cumulativeSum - tar];
            }
    
            prefixSumFreq[cumulativeSum]++;
        }
    
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends
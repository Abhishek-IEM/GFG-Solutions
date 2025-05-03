//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int freq[1000001]={0};
        int count=0;
        int ans=INT_MIN;
        int maxi=-1;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
            maxi=max(maxi,arr[i]);
        }
        for(int i=0;i<=maxi;i++){
            if(freq[i]>0) count++;
            else{
                ans=max(ans,count);
                count=0;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
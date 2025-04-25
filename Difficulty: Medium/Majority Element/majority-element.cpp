//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& nums) {

        // your code here
        int candidate, count = 0, n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                count=1;
                candidate=nums[i];
            }
            else
            {
                if(candidate==nums[i])
                count++;
                else
                count--;
            }
        }
        
        count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==candidate) count++;
        }
        if(count>n/2)
        return candidate;
        else 
        return -1;
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int water=0,index=0,maxheight=arr[0],leftmax=0,rightmax=0;
        
        for(int i=1;i<n;i++)
        {
            if(maxheight<arr[i])
            {
                maxheight=arr[i];
                index=i;
            }
        }
        
        for(int i=0;i<index;i++)
        {
            if(leftmax>arr[i])
            water+=leftmax-arr[i];
            else leftmax=arr[i];
        }
        
        for(int i=n-1;i>index;i--)
        {
            if(rightmax>arr[i])
            water+=rightmax-arr[i];
            else rightmax=arr[i];
        }
        
        return water;
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
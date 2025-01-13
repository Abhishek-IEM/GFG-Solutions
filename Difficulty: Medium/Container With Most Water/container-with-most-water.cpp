//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int area = 0, left = 0, right = arr.size() - 1;
        while(left < right)
        {
            int h = min(arr[left], arr[right]);
            int w = right - left;
            area = max(area, h * w);
            
            if(arr[left] > arr[right]) right--;
            else left++;
        }
        return area;
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
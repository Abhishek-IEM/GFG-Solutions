//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        int n = s.length();
        vector<bool> count(256, 0);
        int first = 0, second = 0, len = 0;
        while(second < n)
        {
            //repeating character
            while(count[s[second]])
            {
                count[s[first]] = 0;
                first++;
            }
            count[s[second]] = 1;
            len = max(len, second - first + 1);
            second++;
        }
        return len;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends
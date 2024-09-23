//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        void lpsfind(vector<int> &lps, string s)
        {
            int pre = 0, suf = 1;
            while(suf < s.size())
            {
                if(s[pre] == s[suf])
                {
                    lps[suf] = pre + 1;
                    suf++, pre++;
                }
                else
                {
                    if(pre == 0)
                    {
                        lps[suf] = 0;
                        suf++;
                    }
                    else pre = lps[pre - 1];
                }
            }
        }
        vector <int> search(string pat, string txt)
        {
            //code here
            vector<int> lps(pat.size(), 0);
            lpsfind(lps, pat);
            int first = 0, second = 0;
            vector<int> ans;
            while(first < txt.size() && second < pat.size())
            {
                if(txt[first] == pat[second])
                {
                    first++, second++;
                    if(second == pat.size())
                    {
                        ans.push_back(first - second + 1);
                        second = lps[second - 1];
                    }
                }
                else
                {
                    if(second == 0) first++;
                    else second = lps[second - 1];
                }
            }
            if(ans.size() > 0) return ans;
            else return {-1};
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n = arr.size(), police = 0, thief = 0, count = 0;
        
        while(police < n && arr[police] != 'P') police++;
        while(thief < n && arr[thief] != 'T') thief++;
        
        while(police < n && thief < n)
        {
            if(abs(police - thief) <= k){
                thief++;
                police++;
                count++;
            }
            else if(police < thief) police++;
            else if(thief < police) thief++;
            
            while(police < n && arr[police] != 'P') police++;
            while(thief < n && arr[thief] != 'T') thief++;
        }
        return count;
    }
};
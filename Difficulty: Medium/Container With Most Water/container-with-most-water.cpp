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

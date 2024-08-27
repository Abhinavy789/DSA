class Solution {
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int>ans;
        
        int large = arr[n-1];
        ans.push_back(large);
        
        for(int i = n-2; i>=0; i--)
        if(arr[i]>=large)
        {
            ans.push_back(arr[i]);
            large = arr[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
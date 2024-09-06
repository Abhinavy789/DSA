class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<int, int> prefix_sum;
        int sum = 0;
        int max_len = 0;
        
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
            
            if(sum==0)
            {
                max_len = i+1;
            }
            
            if(prefix_sum.find(sum)!=prefix_sum.end())
            {
                max_len = max(max_len, i-prefix_sum[sum]);
            }
            else
            {
                prefix_sum[sum]=i;
            }
        }
        return max_len;
    }
};
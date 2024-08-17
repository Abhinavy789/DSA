class Solution {
  public:
    void subset (vector<int> &arr, int index, int n, int sum, vector<int> &ans)
    {
        if(index==n)
        {
            ans.push_back(sum);
            return;
        }
        subset(arr, index+1, n, sum+arr[index], ans);
        subset(arr, index+1, n, sum, ans);
    }
    
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int>ans;
        subset(arr, 0, n, 0, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
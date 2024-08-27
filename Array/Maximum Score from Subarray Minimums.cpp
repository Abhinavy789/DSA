class Solution {
  public:
    int pairWithMaxSum(vector<int> &arr) {
        int n = arr.size();
        
        if (n < 2)
        return -1; 
        
        int max_sum = INT_MIN;
        
       
        for (int i = 0; i < n - 1; i++) {
            int current_sum = arr[i] + arr[i + 1];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
        
        return max_sum;
    }
};

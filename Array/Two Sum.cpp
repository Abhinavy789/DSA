class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int,int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int num = nums[i];
            int balance = target - num;
            if(mp.find(balance) != mp.end()){
                return {mp[balance], i};
            }
            mp[num]=i;
        }
        return {-1, -1};
    }
};
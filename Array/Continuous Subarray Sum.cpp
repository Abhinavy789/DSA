class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mp;

        int sum=0;
        mp[0]=-1;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem=sum%k;

            if(mp.find(rem)!=mp.end())
            {
                if(i-mp[rem]>=2)
                return true;
            }
            else
            {
                mp[rem]=i;
            }
        }
        return false;
    }
};

1. Create an empty hash map to store the remainder and their indices.
2. Initialize the sum to 0.
3. Store a special case in the map: mp[0] = -1 to handle cases where the subarray starts from the beginning.
4. For each element update the sum.
5. Calculate the remainder of the sum divided by k.
6. Check if the remainder is already in the map.
7. If yes check the subarray length is greater than equal to 2 or not, if true return true.
8. If false store the current index for this remainder in the map.
9.If no valid subarray is found during the iteration, return false.

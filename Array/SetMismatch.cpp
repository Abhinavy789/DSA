class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int dup=-1;
        int missing=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])-1]<0)
            {
                dup=abs(nums[i]);
            }
            else
            {
                nums[abs(nums[i])-1]*=(-1);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                missing=(i+1);
                break;
            }
        }
        return {dup,missing};
    }
};

1. We will firstly declare 2 variable dup(to mark the duplicate) and missing(to find the missing number) and initialize them with -1.
2. Now we will iterate through the given array and check the corresponding index by using the absolute value.
3. If the value at the index is negative it means the given value is encountered before and is duplicate.
4. If the value is positive it will change it to negative to mark that the number is encountered.
5. After marking all the numbers we will again iterate to find the missing number.
6. If we find any positive number it means that the number corresponding to that index is missing.
7. Finally return duplicate and missing.
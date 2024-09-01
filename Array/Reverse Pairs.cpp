class Solution {
public:
    int mergeAndCount(vector<int>& ans, int left, int mid, int right)
    {
        int count = 0;
        int j = mid+1;

        for(int i=left; i<=mid; i++)
        {
            while(j<=right && ans[i]>2LL*ans[j])
            {
                j++;
            }
            count+=(j-(mid+1));
        }

        vector<int>temp;
        int i = left, k = mid+1;

        while(i<=mid && k<=right)
        {
            if(ans[i]<=ans[k])
            {
                temp.push_back(ans[i++]);
            }
            else
            {
                temp.push_back(ans[k++]);
            }
        }
        while(i<=mid)
        {
        temp.push_back(ans[i++]);
        }
        while (k <= right)
        {
        temp.push_back(ans[k++]);
        }
        for(int i=left; i<=right; i++)
        {
            ans[i] =  temp[i-left];
        }
        return count;
    }

    int mergeSortandCount(vector<int>& ans, int left, int right)
    {
        if(left>=right)
        return 0;

        int mid = left+(right-left)/2;
        int count = mergeSortandCount(ans, left, mid);
        count+= mergeSortandCount(ans, mid+1, right);
        count+=mergeAndCount(ans, left, mid, right);
        return count;
    }

    int reversePairs(vector<int>& ans) {
        return mergeSortandCount(ans, 0, ans.size()-1);
    }
};
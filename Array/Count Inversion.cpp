class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int mergeAndCount(long long arr[], int left, int mid, int right)
    {
        long long count = 0;
        long long i = left;
        long long j = mid+1;
        long long k = 0;
        vector<long long>temp(right-left+1);
        
        while(i<=mid && j<=right)
        {
            if(arr[i]<=arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                count+=(mid-i+1);
            }
        }
        
        while(i<=mid)
        {
            temp[k++]=arr[i++];
        }
        while(j<=right)
        {
            temp[k++]=arr[j++];
        }
        for(int i=left; i<=right; i++)
        {
            arr[i]=temp[i-left];
        }
        return count;
    }
    
    long long int mergeSortAndCount(long long arr[], int left, int right)
    {
        if(left>=right){
        return 0;
        }
        
        int mid = left+(right-left)/2;
        long long count = 0;
        count+= mergeSortAndCount(arr, left, mid);
        count+= mergeSortAndCount(arr, mid+1, right);
        count+= mergeAndCount(arr,left,mid,right);
        return count;
    }
    
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here
        return mergeSortAndCount(arr, 0, n-1);
    }
};
class Solution {
public:
    int lenOfLongSubarr(int A[], int N, int K) 
    { 
        unordered_map<int, int> sumMap; 
        int sum = 0; 
        int maxLength = 0; 

        for (int i = 0; i < N; i++) {
            sum += A[i]; 
            
            if (sum == K) {
                maxLength = i + 1; 
            }
            if (sumMap.find(sum - K) != sumMap.end()) {
                maxLength = max(maxLength, i - sumMap[sum - K]);
            }
            if (sumMap.find(sum) == sumMap.end()) {
                sumMap[sum] = i; 
            }
        }
        return maxLength; 
    }
};

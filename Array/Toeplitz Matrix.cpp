Intuition:
1. Don't include first row and first column because they dont have any diagonal before them.
2. Start from second row and second column.

Approach:
1. Declare variable m for row and n for column.
2. Iterate from row and column and compare each element with the element diagonally up-left.
3. If any element is not equal to its diagonal up-left neighbor, return false.

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]!=matrix[i-1][j-1])
                return false;
            }
        }
        return true;
    }
};
Things to Remember:
1. The town judge trusts nobody.
2. Everybody (except for the town judge) trusts the town judge.
3. There is exactly one person that satisfies properties 1 and 2.

Approach:
1. Use a count array of size n+1.
2. For trust relations u and v , decrease count[u] because it trusts someone and increase count[v] because it is getting trusted.
3. Iterate through count array if count[i] is equal to n-1 return i as judge.


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector <int> count(n+1);

        for(vector<int> &vec:trust)
        {
            int u = vec[0];
            int v = vec[1];

            count[u]--;
            count[v]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(count[i]==n-1)
            return i;
        }
        return -1;
    }
};
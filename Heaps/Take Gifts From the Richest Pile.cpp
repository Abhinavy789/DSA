class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = 0;
        priority_queue<long long>p;
        for(int i=0; i<gifts.size(); i++)
        {
            p.push(gifts[i]);
        }

        while(k--)
        {
            p.push(sqrt(p.top()));
            p.pop();
        }
        while(!p.empty())
        {
            sum+=p.top();
            p.pop();
        }
        return sum;
    }
};
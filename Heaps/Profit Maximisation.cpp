int Solution::solve(vector<int> &A, int B) {
    int sum = 0;
    priority_queue<int>p;
    for(int i=0; i<A.size(); i++)
    {
        p.push(A[i]);
    }
    while(B>0 && !p.empty())
    {
        sum+=p.top();
        if(p.top()-1>0){
         p.push(p.top() - 1);
        }
        p.pop();
        B--;
    }
    return sum;
}

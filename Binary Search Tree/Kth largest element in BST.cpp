class Solution
{
    public:
    void KLargest(Node *root, int &ans, int &K)
    {
        if(!root)
        return  ;
        KLargest(root->right, ans, K);
        K--;
        if(K==0)
        ans = root->data;
        if(K==0)
        return;
        KLargest(root->left, ans, K);
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int ans;
        KLargest (root, ans, K);
        return ans;
    }
};
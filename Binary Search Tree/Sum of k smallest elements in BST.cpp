void KSum(Node *root, int &sum, int &k)
{
    if(!root)
    return;
    
    KSum(root->left, sum, k);
    k--;
    if(k>=0)
    sum+=root->data;
    if(k<=0)
    return;
    KSum(root->right, sum, k);
}

int sum(Node* root, int k) 
{ 
  
    // Your code here
    int sum = 0;
    KSum(root, sum, k);
    return sum;
} 
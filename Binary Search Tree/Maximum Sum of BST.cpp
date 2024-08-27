class Box
{
    public:
    bool BST;
    int sum;
    int min, max;
    
    Box()
    {
        BST = 1;
        sum = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
};

class Solution {
public:
    Box* find(TreeNode* root, int &Maxsum)
    {
         if(!root)
        {
            return new Box();
        }
        
        Box *Lefthead = find(root->left, Maxsum);
        Box *Righthead = find(root->right, Maxsum);
        Box* head = new Box();
        
        if(Lefthead->BST && Righthead->BST && Lefthead->max < root->val && Righthead->min > root->val)
        {
            head->min = min(root->val, Lefthead->min);
            head->max = max(root->val, Righthead->max);
            head->sum = root->val + Lefthead->sum + Righthead->sum;
            Maxsum = max(Maxsum, head->sum);
            return head;
        }
        else
        {
            head->BST = false;
            return head;
        }
    }

    int maxSumBST(TreeNode* root) {
       int Maxsum = 0;
       find(root, Maxsum);
       return Maxsum; 
    }
};
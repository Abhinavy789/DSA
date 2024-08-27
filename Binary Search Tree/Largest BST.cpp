class Box
{
    public:
    bool BST;
    int size;
    int min, max;
    
    Box()
    {
        BST = 1;
        size = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Box* find(Node* root, int &Totalsize)
    {
         if(!root)
        {
            return new Box();
        }
        
        Box *Lefthead = find(root->left, Totalsize);
        Box *Righthead = find(root->right, Totalsize);
        
        if(Lefthead->BST && Righthead->BST && Lefthead->max < root->data && Righthead->min > root->data)
        {
            Box* head = new Box();
            head->size = 1 + Lefthead->size + Righthead->size;
            head->min = min(root->data, Lefthead->min);
            head->max = max(root->data, Righthead->max);
            Totalsize = max(Totalsize, head->size);
            return head;
        }
        else
        {
            Box* head = new Box();
            head->BST = false;
            head->size = max(Lefthead->size, Righthead->size);
            return head;
        }
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	int Totalsize = 0;
    	find(root, Totalsize);
    	return Totalsize;
    }
};
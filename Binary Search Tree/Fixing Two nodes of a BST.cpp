class Solution {
  public:
    void correctBST( struct Node* root )
    {
        // add code here.
        Node *curr = NULL;
        Node *first = NULL, *second = NULL;
        Node *last = NULL, *present = NULL;
        
        while (root)
        {
            if(!root->left)
            {
                last = present;
                present = root;
                
                if(last && last->data > present->data)
                {
                    if(!first)
                    first = last;
                    second = present;
                }
                root = root->right;
            }
            else
            {
                curr = root->left;
                while (curr->right && curr->right!=root)
                {
                    curr = curr->right;
                }
                
                if(!curr->right)
                {
                    curr->right = root;
                    root = root->left;
                }
                else
                {
                    curr->right = NULL;
                 last = present;
                present = root;
                if(last && last->data > present->data)
                {
                    if(!first)
                    first = last;
                    second = present;
                }
                 root = root->right;
            }
        }
    }
    if (first && second) {
    int num =first->data;
    first->data = second->data;
    second->data = num;
    }
    }
};
Node *deleteNode(Node *root, int target) {
    // your code goes here
    if(!root)
    return NULL;
    if(root->data > target)
    {
    root->left = deleteNode (root->left, target);
    return root;
    }
    else if (root->data < target)
    {
    return root;
    root->right = deleteNode (root->right, target);
    }
    else
    {
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        
        else if(!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        
        else if(!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            Node *child = root->left;
            Node *parent = root;
            while (child->right)
            {
                parent = child;
                child = child->right;
            }
            if(root!=parent)
            {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else
            {
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
}

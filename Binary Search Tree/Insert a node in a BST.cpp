class Solution
{
    public:
        Node* insert(Node* root, int data) {
        
            // Your code goes here
            if (!root)
            {
                Node *temp = new Node(data);
                return temp;
            }
            
            if (data < root->data)
            {
            root->left = insert(root->left, data);
            }
            else if (data > root->data)
            {
            root->right = insert(root->right, data);
            }
            return root;
    }

};
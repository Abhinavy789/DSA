TreeNode* invertTree(TreeNode* root) {
    if (!root)
        return NULL;

    queue<TreeNode*> q;
    q.push(root);

    TreeNode* temp;

    while (!q.empty()) {
        temp = q.front();
        q.pop();
        
        swap(temp->left, temp->right);

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
    return root;
}

int getheight(Node* root) {
    if (!root)
        return 0;
    return root->height;
}

int getbalance(Node* root) {
    return getheight(root->left) - getheight(root->right);
}

Node* rightRotation(Node* root) {
    Node* child = root->left;
    Node* childRight = child->right;
    child->right = root;
    root->left = childRight;

    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    return child;
}

Node* leftRotation(Node* root) {
    Node* child = root->right;
    Node* childLeft = child->left;
    child->left = root;
    root->right = childLeft;

    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    return child;
}

Node* deleteNode(Node* root, int key) {
    if (!root)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        } else if (root->left && !root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* curr = root->right;
            while (curr->left) {
                curr = curr->left;
            }
            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }

    root->height = 1 + max(getheight(root->left), getheight(root->right));

    int balance = getbalance(root);

    if (balance > 1) {
        if (getbalance(root->left) >= 0)
            return rightRotation(root);
        else {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    } else if (balance < -1) {
        if (getbalance(root->right) <= 0)
            return leftRotation(root);
        else {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    } else {
        return root;
    }
}
class Solution {
  public:
    Node* ArrayToBST(vector<int>& arr, int start, int end) {
        if (start > end)
            return NULL;
        
        int mid = start + (end - start) / 2;
        Node* root = new Node(arr[mid]);
        
        root->left = ArrayToBST(arr, start, mid - 1);
        root->right = ArrayToBST(arr, mid + 1, end);
        
        return root;
    }
    
    Node* sortedArrayToBST(vector<int>& nums) {
        return ArrayToBST(nums, 0, nums.size() - 1);
    }
};
class Solution {
public:
    // Function returns the second largest element
    int print2largest(std::vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return -1; 
        
        int largest = INT_MIN;
        int second_largest = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (arr[i] > largest) {
                second_largest = largest;
                largest = arr[i];
            } else if (arr[i] > second_largest && arr[i] != largest) {
                second_largest = arr[i];
            }
        }

        return (second_largest == INT_MIN) ? -1 : second_largest;
    }
};
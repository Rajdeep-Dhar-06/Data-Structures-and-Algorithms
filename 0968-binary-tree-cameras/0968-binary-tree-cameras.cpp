class Solution {
public:
    // Index 0 -> Covered by parent (Root has no camera).
    // Index 1 -> Covers itself (Root has a camera).
    // Index 2 -> Covered by child (Root has no camera).
    vector<int> rec(TreeNode* root) {
        if (root == nullptr) {
            return {0, 10000, 0};
        }

        vector<int> L = rec(root->left);
        vector<int> R = rec(root->right);

        int s0 = min(L[1], L[2]) + min(R[1], R[2]);

        int s1 = 1 + min({L[0], L[1], L[2]}) + min({R[0], R[1], R[2]});

        int s2 = min({L[1] + R[2], L[2] + R[1], L[1] + R[1]});

        return {s0, s1, s2};
    }

    int minCameraCover(TreeNode* root) {
        vector<int> ans = rec(root);
        return min(ans[1], ans[2]);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
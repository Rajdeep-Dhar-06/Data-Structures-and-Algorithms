class Solution {
public:
    struct node {
        int cnt;
        node* child[2];
        node() {
            cnt = 0;
            child[0] = child[1] = nullptr;
        }
    };

    struct trie {
        node* root;
        trie() { root = new node(); }

        void insert(int x) {
            node* curr = root;
            curr->cnt++; // increment root

            for (int i = 30; i >= 0; i--) {
                int bit = (x >> i) & 1;

                if (curr->child[bit] == nullptr)
                    curr->child[bit] = new node();

                curr = curr->child[bit];
                curr->cnt++;
            }
        }

        void erase(int x) {
            node* curr = root;
            curr->cnt--;

            for (int i = 30; i >= 0; i--) {
                int bit = (x >> i) & 1;

                if (curr->child[bit] == nullptr)
                    return;

                curr = curr->child[bit];
                curr->cnt--;
            }
        }

        int maxXorPairVal(int x) {
            node* curr = root;
            int y = 0;

            for (int i = 30; i >= 0; i--) {
                int xbit = (x >> i) & 1;
                int ybit = 1 ^ xbit;

                if (curr->child[ybit] == nullptr || curr->child[ybit]->cnt == 0)
                    ybit = xbit;

                y |= (ybit << i);
                curr = curr->child[ybit];
            }

            return x ^ y;
        }
    };

    int maxXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pf(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pf[i + 1] = pf[i] ^ nums[i];
        }
        int ans = 0;
        deque<int> mx;
        deque<int> mn;
        trie bt;
        bt.insert(0);
        int i = 0;
        for (int j = 0; j < n; j++) {
            while (!mx.empty() && nums[mx.back()] <= nums[j])
                mx.pop_back();
            while (!mn.empty() && nums[mn.back()] >= nums[j])
                mn.pop_back();
            mx.push_back(j);
            mn.push_back(j);

            while (i <= j && nums[mx.front()] - nums[mn.front()] > k) {
                bt.erase(pf[i]);
                i++;
                if (mx.front() < i)
                    mx.pop_front();
                if (mn.front() < i)
                    mn.pop_front();
            }

            ans = max(ans, bt.maxXorPairVal(pf[j+1]));
            bt.insert(pf[j+1]);
        }

        return ans;
    }
};
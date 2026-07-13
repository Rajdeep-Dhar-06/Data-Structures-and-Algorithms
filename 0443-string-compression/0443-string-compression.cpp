class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0, n = chars.size();
        while(i < n){
            char ch = chars[i];
            int count  = 0;

            while(i < n && chars[i] == ch){
                i++;
                count++;
            }

            chars[j++] = ch;

            if (count > 1) {
                string countStr = to_string(count);
                for (char digit : countStr) {
                    chars[j++] = digit;
                }
            }
        }

        return j;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
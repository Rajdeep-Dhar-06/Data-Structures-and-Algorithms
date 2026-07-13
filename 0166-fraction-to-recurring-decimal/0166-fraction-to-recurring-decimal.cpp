class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if(num == 0) return "0";
        string ans = "";
        if((num > 0 && den < 0) || (num < 0 && den > 0)) ans += "-";
        long long n = abs((long long)num);
        long long d = abs((long long)den);
        long long bef = n / d;
        long long aft = n % d;
        ans += to_string(bef);
        if(aft == 0) return ans;
        ans += ".";
        unordered_map<long long, int> mp;
        string res = "";
        while(aft != 0){
            if(mp.find(aft) != mp.end()){
                res.insert(mp[aft], "(");
                res += ")";
                break;
            }

            mp[aft] = res.length();
            
            aft *= 10;
            res += to_string(aft / d);
            aft %= den;
        }

        return ans + res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
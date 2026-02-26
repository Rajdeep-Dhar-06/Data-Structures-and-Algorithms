class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        map<char, char> mp1;
        map<char, char> mp2;
        int n = s1.size();
        for(int i=0; i<n; i++){
            char a = s1[i];
            char b = s2[i];
            if(mp1.find(a) == mp1.end() && mp2.find(b) == mp2.end()){
                mp1[a] = b;
                mp2[b] = a;
            }
            if(mp1[a] != b || mp2[b] != a) return false;
         
        }
        return true;
    }
};
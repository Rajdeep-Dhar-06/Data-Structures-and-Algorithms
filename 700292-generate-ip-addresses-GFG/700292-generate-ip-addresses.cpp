class Solution {
  public:
    vector<string> ans;
    void backtrack(string &s, int i, int dot, string t){
        int n = s.size();
        if(dot==3){
            if(i==n || n-i>3) return;
            if(i+1<n && s[i]=='0') return;
            if(stoi(s.substr(i))<=255)
                ans.push_back(t+s.substr(i));
            return;
        }
        string x = "";
        for(int j=i; j<min(n,i+3); j++){
            x += s[j];
            if(x=="0"){
                backtrack(s, j+1, dot+1, t+"0.");
                break;
            }
            else{
                if(stoi(x)<=255)
                backtrack(s, j+1, dot+1, t+x+".");
            }
        }
    }
    vector<string> generateIp(string &s) {
       ans.clear();
       backtrack(s,0,0,"");
       return ans;
    }
};
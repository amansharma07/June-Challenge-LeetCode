class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int j=0;
        for(int i=0;i<n && j<m; i++)
            if(s[j]==t[i])
                j++;
        return (j==m);
    }
};
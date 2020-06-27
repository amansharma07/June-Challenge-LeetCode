class Solution {
public:
    int numSquares(int n) {
        if(n<=3)
            return n;
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i=4; i<=n; i++)
        {
            dp[i] = i;
            for(int p=1; p<=ceil(sqrt(i)); p++)
            {
                int t = p*p;
                if(t>i)
                    break;
                dp[i] = min(dp[i], 1+dp[i-t]);
            }
        }
        return dp[n];
    }
};

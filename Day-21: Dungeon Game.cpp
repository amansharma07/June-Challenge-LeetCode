class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        arr[m-1][n-1] = (arr[m-1][n-1]>0)?1:abs(arr[m-1][n-1])+1;
        for(int i=n-2; i>=0; i--)
          arr[m-1][i] = max(arr[m-1][i+1]-arr[m-1][i],1);
        for(int i=m-2; i>=0; i--)
          arr[i][n-1] = max(arr[i+1][n-1]-arr[i][n-1],1);
        for(int i=m-2; i>=0; i--)
          for(int j=n-2; j>=0; j--)
            arr[i][j] = max(min(arr[i+1][j], arr[i][j+1])-arr[i][j], 1);
        return arr[0][0];
    }
};

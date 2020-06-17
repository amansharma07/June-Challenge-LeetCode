class Solution {
public:
    int dirx[4]={-1, 0, 1, 0};
    int diry[4]={0, -1, 0, 1};
    bool isSafe(int x, int y, int row, int col)
    {
        if(x>=0 && y>=0 && x<row && y<col)
            return true;
        return false;
    }
    void check(vector<vector<char> >&vec,int i,int j,int row,int col){
		if(isSafe(i,j,row,col) && vec[i][j]=='O'){
			vec[i][j]='1';
			for(int p=0; p<4; p++)
                check(vec,i+dirx[p],j+diry[p],row,col);
		}
	}
    void solve(vector<vector<char>>& board) {
        int i,j;
        int row=board.size();
        if(!row)    return;
        int col=board[0].size();
		for(i=0;i<row;i++){
			check(board,i,0,row,col);
			check(board,i,col-1,row,col);
		}
		for(j=0;j<col;j++){
			check(board,0,j,row,col);
			check(board,row-1,j,row,col);
		}
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				if(board[i][j]=='O')
					board[i][j]='X';
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				if(board[i][j]=='1')
					board[i][j]='O';
    }
};

class Solution {
public:
    int abc(int n,int m,vector<vector<int>> x,int i,int j){
        if(i<0||i>=n||j<0||j>=m) return 0;
        return x[i][j];
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>> x(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                x[i][j]=board[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int z=0;
                for(int k1=i-1;k1<=i+1;k1++){
                    for(int k2=j-1;k2<=j+1;k2++){
                        if(!(k1==i && k2==j)) z+=abc(n,m,x,k1,k2);
                    }
                }
                if(x[i][j]==1 &&(z<2 || z>3)) board[i][j]=0;
                else if(x[i][j]==0 && z==3) board[i][j]=1;
            }
        }
    }
};
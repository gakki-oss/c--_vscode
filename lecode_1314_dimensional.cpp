#include<iostream>
#include<vector>

using namespace std;

class Solution { 
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> PreSum(m+1,vector<int>(n+1,0));
        vector<vector<int>> answer(m,vector<int>(n,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                PreSum[i][j]=mat[i-1][j-1]+PreSum[i][j-1]+PreSum[i-1][j]-PreSum[i-1][j-1];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int row1 = max(i-k,0),col1=max(j-k,0);
                int row2 = min(i+k,m-1),col2=min(j+k,n-1);   
                answer[i][j] = PreSum[row2+1][col2+1]-PreSum[row1][col2+1]-PreSum[row2+1][col1]+PreSum[row1][col1];
            }
        }
         return answer;
    }
   
};


int main()
{
    Solution res;
    vector<vector<int>> mat(3, vector<int>(3, 0));
    cout << "请输入数组元素:" << endl;
    for(auto &row : mat)
    {
        for(auto &i:row)
        {
            cin >> i;
        }
    }
    vector<vector<int>> ans = res.matrixBlockSum(mat, 1);
        for(auto &row1 : ans)
    {
        for(auto &i1:row1)
        {
            cout << i1 << " ";
        }
        cout << endl;
    }
    return 0;
}
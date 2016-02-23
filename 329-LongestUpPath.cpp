#include <iostream>
#include <vector>
using namespace std;
struct direction{
  int row;
  int lie;
};
class Solution{
public:
    int longestIncreasingPath(vector<vector<int> > & matrix){

        vector<direction> way;
        vector<vector<bool>> vis;
        int rowcount;
        int liecount;
        vector<bool> line;
        vector<int> mem;
        vector<vector<int>> memo;
        if (matrix.empty()) {
            return 0;
        }
        rowcount=matrix.size()-1;
        liecount=matrix[0].size()-1;

        for (int k=0; k<=rowcount; k++) {
            line.clear();
            for (int b=0;b<=matrix[k].size();b++) {
                line.push_back(false);
            }
            vis.push_back(line);
        }
        for (int k=0; k<=rowcount; k++) {
            mem.clear();
            for (int b=0;b<=matrix[k].size();b++) {
                mem.push_back(-1);
            }
            memo.push_back(mem);
        }

        direction temp;
        int resultlength=-1;
        temp.row=-1,temp.lie=0;
        way.push_back(temp);//上
        temp.row=0,temp.lie=-1;
        way.push_back(temp);//左
        temp.row=0,temp.lie=1;
        way.push_back(temp);//右
        temp.row=1,temp.lie=0;
        way.push_back(temp);//下
        int i,j;
        for (i=0;i<=rowcount;i++)
        {
            for(j=0;j<=matrix[i].size();j++)
            {
                temp.row=i;
                temp.lie=j;
                resultlength=max(resultlength,findokway(i,j,rowcount,matrix[i][j],liecount,way,vis,matrix,memo));
            }
        }
        return resultlength;
    }
    bool panduan(int i,int j,int rowcount,int liecount,vector<vector<bool>> &vis) {
        bool panduan;
        if(i<0||i>rowcount||j<0||j>liecount)
            panduan=false;
        else
            panduan= true;
        return panduan;
    }
    int findokway(int tti,int ttj,int rowcount,int number,int liecount,vector<direction> &way,vector<vector<bool>> &vis,vector<vector<int>> &matrix,vector<vector<int>> &memo){
        int i,ti,tj;
        if (memo[tti][ttj]!=-1) {
            return memo[tti][ttj];
        }else{
        int maxlength=1;
        if(tti<0||tti>rowcount||ttj<0||ttj>liecount||vis[tti][ttj]==true){
            maxlength=-2;
        }else{
            for(i=0;i<=way.size()-1;i++){

                ti=tti+way[i].row;
                tj=ttj+way[i].lie;
                if(panduan(ti,tj,rowcount,liecount,vis)&&(matrix[ti][tj]>number))
                {
                    vis[tti][ttj]=true;
                    maxlength=max(maxlength,findokway(ti,tj,rowcount,matrix[ti][tj],liecount,way,vis,matrix,memo)+1);
                    vis[tti][ttj]=false;
                }
            }
        }
        if (maxlength!=-2) {
            memo[tti][ttj]=maxlength;
        }
        return maxlength;
        }
    }

};
int main(int argc, const char * argv[]) {
    int a=5;
    int b=10;
    vector<vector<int> > matrix(b);
    //bool ji=true;
    //int a;

    for(int i=0;i<b;i++)
        matrix[i].resize(a);
        
    for(int i=0;i<b;i++)
    {
        //a=i*3;
        for(int j=0;j<a;j++)
            if (i%2==1) {
                matrix[i][j]=b*i+j;
            }else
                matrix[i][a-j-1]=b*i+j;
    }

    Solution sol;
    int length=sol.longestIncreasingPath(matrix);
    std::cout<<"最长路径的长度为"<<length<<endl;
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

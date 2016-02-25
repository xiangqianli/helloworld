#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    bool isValidSerialization(string preorder){
        int length1=preorder.size();
        vector<int> scanaround(length1+1,false);
        int count=0;
        int tempjudge=0;
        int height=1;
        char temp;
        if(length1==1&&preorder[0]!='#')
            return false;
        for (int i=0; i<length1; i++) {
            temp=preorder[i];
            if (temp!='#') {
                while (i<length1&&preorder[i]!=',') {
                    i++;
                }
                if(tempjudge==2){
                    count--;
                    tempjudge=0;
                }else if(tempjudge==1){tempjudge=0;}
                 else
                    count++;
                while (scanaround[count]==2){
                    scanaround[count]=0;
                    count--;
                }
                scanaround[count]++;
            }else{
                if (tempjudge==0) {
                    if (count>1&&scanaround[count]==1) {//左子结点为数据，右子结点为空，则不另起一行
                        tempjudge=0;
                    }else{//另起一行
                        count++;
                        tempjudge++;
                    }
                    scanaround[count]++;
                }else if(tempjudge==2){//由错误用例推出的，空结点后接空结点作为子结点，或作为祖父的兄弟结点
                    while (scanaround[count]%2==0){
                        scanaround[count]=0;
                        count--;
                    }
                    if (count<=1) //是<=而不是==，否则＃＃＃用例会出错
                        return  false;
                    else
                        scanaround[count]=0;
                }
                else{//tempjudge==1
                    tempjudge++;
                    scanaround[count]=0;
                }
                i++;
            }
            height=max(height,count);
        }
        bool lastscan=true;
        if (scanaround[1]!=1) {
            lastscan=false;
        }else{
            for (int i=2; i<=height; i++) {
                if (scanaround[i]==1) {
                    lastscan=false;
                }
            }
        }
        return lastscan;
    }
};
int main(int argc, const char * argv[]) {
    string preorder="#,#,#";
    Solution sol;
    bool length=sol.isValidSerialization(preorder);
    cout<<length<<"长度"<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}

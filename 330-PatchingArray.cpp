#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int minPatches(vector<int> &nums,int n){
        vector<int> mynums=nums;
        int add=0;//添加的元素数目
        long long sum=0;//逐渐生长直到n,需为long long型否则增加到一定程度后会溢出
        int i=0;
        int exist=mynums.size();
        while (sum<n) {
            if(i>=exist||mynums[i]>sum+1)
            {
                add++;
                sum=2*sum+1;//向array中添加元素sum+1后，sum被更新
            }else if (mynums[i]<=sum+1)
            {
                sum=sum+mynums[i];
                i++;
            }
        }
        return  add;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> nums(4);
    int n=2147483647;
    nums[0]=1;
    nums[1]=2;
    nums[2]=31;
    nums[3]=33;
    Solution sol;
    int length=sol.minPatches(nums, n);
    cout<<length<<"长度"<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}

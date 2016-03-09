//
//  main.cpp
//  leecode
/*  算法思路：要求出现3个数能递增，首先想到会出现两对分离的递增数据对即可，但是这两对数据对之间有些关系要讨论。
 比如说序列{1，2，3，4，5}有两对递增的数据对{1，2}和{2，3}，成立；
 序列{5，1，5，5，3，4}首先出现一对递增的数据对{1，5}，和之后出现的{3，4}组成两对数据对，这个为什么成立呢，因为扫描到3时应该更新第一对数据对为{1，3}，只要找到比3再大的数就可以了，也就是找到一对递增数据对的第二个数比3大；
 序列{5，5，4，3，9，3，1，2，3}又有点特殊，首先出现的递增数据对是{3，9}，但之后出现数据对{1，2}，无法组成连续的数据对，这个时候更新第一组数据对为最大值较小的{1，2}，继续寻找第二对即可。这里为什么要更新呢，因为需要满足的条件越低越好啊。
 而对于序列{5，5，4，3，9，3，1，10}，第一对数据对是{3，9}，第二队数据对是{1，10}，10比9大，即可判断成立，和第二个例子类似。
 */
//  Created by lxq on 16/3/3.
//  Copyright (c) 2016年 lxq. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    bool increasingTriplet(vector<int>& nums){
        bool result=false;
        bool start=false;
        long long length=nums.size();
        if (length==0) {
            return false;
        }
        int temp=nums[0];
        int startvalue = 0;
        for (int x=1; x<length; x++) {
            if (nums[x]>nums[x-1]){
                if (start==false) {//找到第一对数据对
                    temp=nums[x];
                    startvalue=nums[x-1];
                    start=true;
                }
                else if(start==true){
                    if (nums[x]<temp){//更新第一对数据对，降低待满足的条件
                        temp=nums[x];
                        startvalue=nums[x-1];}
                    else if (temp<nums[x])//找到第二对数据对
                        return true;
                }
            }else if (start==true){//适时更新第一对数据对的最大值
                if (nums[x]>startvalue&&nums[x]<temp)
                    temp=nums[x];
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> tickets(10,0);
    tickets[0]=1;
    tickets[1]=2;
    tickets[2]=1;
    tickets[3]=2;
    tickets[4]=1;
    tickets[5]=1;
    tickets[6]=2;
    Solution sol;
    bool result=sol.increasingTriplet(tickets);
    
    // insert code here...
    if (result==true)
        std::cout << "Hello, World!\n";
    else
        cout<<"Bye,World!\n";
    return 0;
}

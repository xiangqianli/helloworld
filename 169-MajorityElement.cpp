//
//  169MajorityElement.cpp
//  leecode
//
//  Created by lixiangqian on 16/10/25.
//  Copyright © 2016年 lixiangqian. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <stdlib.h>
using namespace std;
int majorityElement(vector<int> & nums){
    if(nums.size()==1)
        return *nums.begin();
    //注意for循环里还是要判断i<nums.size()，否则会溢出
    for(int i=0,j=1;nums.size()>4&&i<nums.size();){
        if(j<nums.size()){
            if(nums[i]!=nums[j]){
                vector<int>::iterator ii=nums.begin()+i;
                vector<int>::iterator jj=nums.begin()+j;
                nums.erase(ii);
                nums.erase(jj-1);
            }else{
                j++;
            }
        }else{
            if(nums[i]!=nums[j]){
                vector<int>::iterator ii=nums.begin()+i;
                nums.erase(ii);
                nums.pop_back();
            }else{
                i++;
            }
            
        }
    }
    for (int i=0; i<4; i++) {
        for(int j=0;j<i;j++){
            if(nums[j]==nums[i]){
                return nums[j];
            }
        }
    }
    return 0;
}
int main(){
    vector<int> nums;
    nums.push_back(12);
//    nums.push_back(52);
//    nums.push_back(12);
//    nums.push_back(70);
//    nums.push_back(12);
//    nums.push_back(61);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(50);
//    nums.push_back(72);
//    nums.push_back(82);
//    nums.push_back(12);
//    nums.push_back(11);
//    nums.push_back(25);
//    nums.push_back(28);
//    nums.push_back(43);
//    nums.push_back(40);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(53);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(98);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(92);
//    nums.push_back(81);
//    nums.push_back(2);
//    nums.push_back(12);
//    nums.push_back(15);
//    nums.push_back(40);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(9);
//    nums.push_back(12);
//    nums.push_back(31);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(77);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(50);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(93);
//    nums.push_back(41);
//    nums.push_back(92);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(37);
//    nums.push_back(48);
//    nums.push_back(14);
//    nums.push_back(12);
//    nums.push_back(70);
//    nums.push_back(82);
//    nums.push_back(12);
//    nums.push_back(80);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(56);
//    nums.push_back(30);
//    nums.push_back(12);
//    nums.push_back(8);
//    nums.push_back(12);
//    nums.push_back(50);
//    nums.push_back(12);
//    nums.push_back(20);
//    nums.push_back(12);
//    nums.push_back(21);
//    nums.push_back(97);
//    nums.push_back(12);
//    nums.push_back(42);
//    nums.push_back(12);
//    nums.push_back(10);
//    nums.push_back(12);
//    nums.push_back(38);
//    nums.push_back(73);
//    nums.push_back(15);
//    nums.push_back(9);
//    nums.push_back(11);
//    nums.push_back(79);
//    nums.push_back(12);
//    nums.push_back(12);
//    nums.push_back(28);
//    nums.push_back(51);
//    nums.push_back(12);
//    nums.push_back(15);
//    nums.push_back(12);


//    nums.push_back(4);
//    nums.push_back(8);
    int result = majorityElement(nums);
    cout<<"helloworld"<<endl;
    cout<<result<<endl;
}

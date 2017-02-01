//
//  189-Rotate Array.cpp
//  leecode
//  讨论中的解法1，时间复杂度O(N),空间复杂度O(N);可以将空间复杂度降为O(1),如解法2和解法3所示
//  Created by lixiangqian on 17/1/31.
//  Copyright © 2017年 lixiangqian. All rights reserved.
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
void rotate(vector<int>& nums, int k) {
    long s = nums.size();
    if(k%s == 0){
        return;
    }else{
        k = k%s;
    }
    vector<int> tempnums(s);
    for (long j = 0; j < s; j++) {
        tempnums[j] = nums[j];
    }
    for (long i = 0; i < s; i++ ) {
        nums[(i+k)%s] = tempnums[i];
    }
}
int main(){
    vector<int> nums(2);
    nums[0] = 1;
    nums[1] = 2;
    rotate(nums, 1);
    for (long i =0; i<nums.size(); i++) {
        cout<<nums[i]<<endl;
    }
    cout<<"hello world!"<<endl;
    return 0;
}

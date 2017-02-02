//
//  35-Search Insert Position.cpp
//  leecode
//
//  Created by lixiangqian on 17/2/2.
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
int searchInsert(vector<int>& nums, int target) {
    long s = nums.size();
    if (s>2 && target > nums[s/2]) {
        vector<int> t(nums.begin()+s/2+1,nums.end());
        return (int)s/2+ 1 + searchInsert(t, target);
    }else if (s>2 && target < nums[s/2]){
        vector<int> t(nums.begin(),nums.begin()+s/2);
        return searchInsert(t, target);
    }else if(s>2 && target == nums[s/2]){
        return (int)s/2;
    }else if(s>1 && target > nums[1]){
        return 2;
    }else if(target <= nums[0]){
        return 0;
    }else{
        return 1;
    }
}
int main(){
    vector<int> nums(3);
    nums[0] = 1;
    nums[1] = 3;
    nums[2] = 5;
    int result = searchInsert(nums, 4);
    cout<< result <<endl;
    cout<<"hello world!"<<endl;
    return 0;
}

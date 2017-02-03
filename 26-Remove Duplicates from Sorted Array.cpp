//
//  26-Remove Duplicates from Sorted Array.cpp
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
int removeDuplicates(vector<int>& nums) {
    int s = (int)nums.size();
    for (int i =1 ; i<nums.size(); i++) {
        if (nums[i] == nums[i-1]) {
            s--;
            //之前忘了下面这两行
            i--;
            nums.erase(nums.begin()+i);
        }
        /*  不用erase，来降低时间复杂度
             if (nums[i] == nums[i-1]) {
                count++;
            }else{
                nums[i-count] = nums[i];
            }
        */
    }
    return s;
}
int main(){
    vector<int> nums(4);
    nums[0] = 1;
    nums[1] = 3;
    nums[2] = 3;
    nums[3] = 5;
    int result = removeDuplicates(nums);
    cout<< result <<endl;
    cout<<"hello world!"<<endl;
    return 0;
}

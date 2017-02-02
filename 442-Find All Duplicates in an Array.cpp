//
//  442-Find All Duplicates in an Array.cpp
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

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[abs(nums[i])-1]>0) {
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }else if (nums[abs(nums[i])-1]<0){
            result.push_back(abs(nums[i]));
        }
    }
    return result;
}

int main(){
    vector<int> nums(10);
    nums[0] = 1;
    nums[1] = 4;
    nums[2] = 2;
    nums[3] = 5;
    nums[4] = 3;
    nums[5] = 3;
    nums[6] = 6;
    nums[7] = 9;
    nums[8] = 9;
    nums[9] = 2;
    vector<int> result = findDuplicates(nums);
    for (int i = 0; i < result.size(); i++) {
        cout<< result[i] <<endl;
    }
    cout<<"hello world!"<<endl;
    return 0;
}

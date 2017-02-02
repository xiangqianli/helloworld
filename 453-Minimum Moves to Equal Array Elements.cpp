//
//  453-Minimum Moves to Equal Array Elements.cpp
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
int minMoves(vector<int> & nums){
    int sum =0;
    int min = nums[0];
    for (int i =0; i < nums.size(); i++) {
        sum += nums[i];
        min = min<nums[i]?min:nums[i];
    }
    return sum - min*(int)nums.size();
}

int main(){
    vector<int> nums(3);
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    int result = minMoves(nums);
    cout<<result<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}

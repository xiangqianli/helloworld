//
//  27-Remove Element.cpp
//  leecode
//
//  Created by lixiangqian on 17/2/3.
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
int removeElement(vector<int>& nums, int val) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == val) {
            count++;
        }else{
            nums[i-count] = nums[i];
        }
    }
    return (int)nums.size() - count;
}
int main(){
    vector<int> nums(6);
    nums[0] = 1;
    nums[1] = 3;
    nums[2] = 4;
    nums[3] = 3;
    nums[4] = 5;
    nums[5] = 3;
    int result = removeElement(nums, 3);
    cout<< result <<endl;
    cout<<"hello world!"<<endl;
    return 0;
}

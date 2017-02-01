//
//  108. Convert Sorted Array to Binary Search Tree.cpp
//  leecode
//
//  Created by lixiangqian on 17/2/1.
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums) {
    float s = nums.size();
    if(s>0){
        int mx = nums[0+floorf(s/2)];
        TreeNode *t= new TreeNode(mx);
        vector<int> tt(nums.begin(),nums.begin()+floorf(s/2));
        t->left = sortedArrayToBST(tt);
        vector<int> ss(nums.begin()+floorf(s/2)+1, nums.end());
        t->right = sortedArrayToBST(ss);
        return t;
    }else{
        return NULL;
    }
}
int main(){
    vector<int> nums(6);
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    nums[3] = 4;
    nums[4] = 5;
    nums[5] = 6;
    TreeNode * result = sortedArrayToBST(nums);
    cout<<result->val<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}

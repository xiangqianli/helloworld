//
//  404-SumofLeftLeaves.cpp
//  leecode
//
//  Created by lixiangqian on 16/10/31.
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
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
int sumOfLeftLeaves(TreeNode * root){
    int r =0;
    TreeNode * p = root;
    while (p!=NULL) {
        TreeNode * q = p;
        //为了避免把最右结点计算进去，要计算进去左叶结点的最右结点
        if(q->left!=NULL && q->left->left==NULL && q->left->right==NULL){
            r+=q->left->val;
        }else if(q->left!=NULL){
            q=q->left;
            int tr=sumOfLeftLeaves(q);
            r+=tr;
        }
        p=p->right;
    }
    
    return r;
}
int main(){
    TreeNode * root = new TreeNode(sizeof(TreeNode));
//    root->val = 3;
//    TreeNode r1(9),r2(15),r3(7);
//    TreeNode r4(20);
//    r4.right = &r3;
//    r4.left = &r2;
//    root->left = &r1;
//    root->right = &r4;
    root->val = 1;
    TreeNode r1(2);
    root->left = &r1;
    int r = sumOfLeftLeaves(root);
    cout<<"hello world!"<<endl;
    cout<<r<<endl;
    return 0;
}

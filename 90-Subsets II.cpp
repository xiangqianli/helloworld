//
//  main.cpp
//  test
//
//  Created by lxq on 16/9/9.
//  Copyright © 2016年 lxq. All rights reserved.
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

void DFS(vector<vector<int>> *resultlist, vector<int> originlist, vector<int> walk, int path){
    resultlist->push_back(walk);
    for(int i=path; i < originlist.size(); i++){
        //加i>path是因为怕i为0，i-1会报错；另一方面配合后一句主要解决不让同样的数在不同的组合里重复出现。
        //但是比如1，3，4，4组合，[4，4]是可以出现的，[1,3,4,4]也是可以出现的
        if(i>path && originlist[i-1]==originlist[i]) continue;
        walk.push_back(originlist[i]);
        DFS(resultlist, originlist, walk, i+1);
        walk.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    vector<int> num(4);
    num[0]=1;
    num[1]=4;
    num[2]=4;
    num[3]=3;
    sort(num.begin(), num.end());
    vector<vector<int>> resultlist;
    vector<int> walk;
    DFS(&resultlist, num, walk, 0);
    for(int i=0; i<resultlist.size(); i++){
        vector<int> tempresult = resultlist[i];
        for(int j=0; j<tempresult.size(); j++){
            cout<< tempresult[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

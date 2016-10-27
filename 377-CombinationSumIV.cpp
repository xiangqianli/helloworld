//
//  39-CombinationSum.cpp
//  leecode
//
//  Created by lixiangqian on 16/10/26.
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
int combinationSum4(vector<int> &numbers,int target){
    sort(numbers.begin(), numbers.end());
    int t[target+1];
    memset(t, 0, (target+1)*sizeof(int));
    //当numbers中出现一样的数时，将自行加一
    t[0]=1;
    for(int i=1;i<=target;i++){
        //注意避免numbers为空时出现运行时错误，要把number[j]的判断条件放在后面
        for(int j=0;j<numbers.size() &&numbers[j]<=i;j++){
            //规划条件，注意与最少硬币问题有所不同
            int temp = i-numbers[j];
            t[i]=t[i]+t[temp];
        }
    }
    return t[target];
}
int main(){
    int target=200;
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(50);

    int r = combinationSum4(numbers,target);
    cout<<"========"<<endl;
    cout<<r<<endl;
    return 0;
}

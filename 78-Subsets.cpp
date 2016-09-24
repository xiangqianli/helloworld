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

int main(int argc, const char * argv[]) {
    int num[3]={1,2,3};
    int size = sizeof(num)/4;
    long long resultSize = pow(2,size);
    long long module[size];
    for(int i=0;i<size;i++)
        module[i]=1LL<<i;
    int resultlist[resultSize][size];
    long long resultcount = resultSize-1;
    for(long long step=0LL; resultcount >=0; step++){
        int stepcount=0;
        for (int i=0; i<size; i++) {
            if(step & module[i]){
                resultlist[resultSize-1-resultcount][stepcount]=num[i];
                //printf("%lld %d\n",resultSize-1-resultcount,stepcount);
                //printf("%d\n",num[i]);
                stepcount++;
            }
        }
        resultcount--;
    }
    return 0;
}

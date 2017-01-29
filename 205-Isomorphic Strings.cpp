//
//  205-Isomorphic Strings.cpp
//  leecode
//
//  Created by lixiangqian on 17/1/29.
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

bool isIsomorphic(string s, string t) {
    long ss = s.size();
    long st = t.size();
    
    if (s == "" && t=="") {
        return true;
    }else if(ss != st){
        return false;
    }else{
        bool isIsomorphic = true;
        long stot[200];//200个 包含所有ascii字符
        bool checks[200];
        memset(stot, -1, sizeof(stot));
        memset(checks, false, sizeof(checks));
        for (long i = 0; i<ss; i++) {
            long charsnum = s[i] - ' ';
            long chartnum = t[i] - ' ';
            if(stot[charsnum] == -1 && checks[chartnum] == false){//两个字母不能映射到同一个字母, 同一个字母不能映射成不同的字母
                stot[charsnum] = chartnum;
                checks[chartnum] = true;
            }else if (stot[charsnum] != chartnum){
                isIsomorphic = false;
                break;
            }
        }
        return isIsomorphic;
    }
}
int main(){
    string s = "aa";
    string t = "ab";
    bool result = isIsomorphic(s, t);
    cout<<result<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}

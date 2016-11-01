//
//  392-IsSubsequence.cpp
//  leecode
//
//  Created by lixiangqian on 16/11/1.
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
bool isSubsequence(string s, string t) {
    bool panduan=true;
    long ss = s.size();
    long st = t.size();
    int step = 0;
    for(int i=0;i<st;i++){
        int j;
        for(j=step;j<ss;j++){
            if (s[j]==t[i]){
                step=j+1;
                break;
            }
        }
        if(j==ss){
            panduan=false;
            break;
        }
    }
    return panduan;
}
int main(){
    string s = "ahbgdc";
    string t = "axc";
    bool r = isSubsequence(s, t);
    cout<<"hello world!"<<endl;
    cout<<r<<endl;
    return 0;
}

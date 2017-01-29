//
//  387-First Unique Character in a String.cpp
//  leecode
//  字符串，找第一个唯一出现的字符的下标，默认只有小写字母
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

int firstUniqChar(string s) {
    if (s=="") {
        return -1;
    }
    long ss = s.size();
    long num[26][2];
    memset(num, -1, sizeof(num));
    for (long i=0; i<ss ; i++) {
        long charnum = s[i] - 'a';
        if (num[charnum][0]==-1) {
            num[charnum][0]=0;
            num[charnum][1]=i;
        }else{
            num[charnum][0]++;
        }
    }
    int minindex = -1;
    for (long j=0; j<26; j++) {
        int tempindex=-1;
        cout<<"-==================-"<<j<<endl;
        cout<<minindex<<endl;
        if (num[j][0]==0 && num[j][1]>-1) {
            tempindex = (int)num[j][1];
            cout<<num[j][0]<<" "<<tempindex<<endl;
        }
        //注意if判断条件不要写错
        if ((minindex == -1)||(tempindex != -1 && minindex > tempindex)) {
            minindex = tempindex;
        }
    }
    return minindex;
}

int main(){
    string s = "loveleetcode";
    int result = firstUniqChar(s);
    cout<< result<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}

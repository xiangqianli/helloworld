//
//  415-Add Strings.cpp
//  leecode
//  用string转char[]的写法：
/*
char  ll[2];
    ll[1]= '\0';
    char  nn[2];
    nn[1]= '\0';
    for (long i = 0; i < max(len1, len2); i++) {
        ll[0]= i<len1?num1[len1 - i - 1]:'0';
        
        nn[0]= i<len2?num2[len2 - i - 1]:'0';
        int l = atoi(ll);
        int n = atoi(nn);
*/
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

string addStrings(string num1, string num2) {
    long len1 = num1.size();
    long len2 = num2.size();
    string result = "";
    bool up = false;
    for (long i = 0; i < max(len1, len2); i++) {
        int l = i<len1?num1[len1 - i - 1]-'0':0;
        int n = i<len2?num2[len2 - i - 1]-'0':0;
        
        if (up) {
            result = to_string((l+ n + 1)%10) + result;
            up = (l+n+1)>=10;
        }else{
            result = to_string((l+ n)%10) + result;
            up = (l+n)>=10;
        }
    }
    
    if (up) {
        result = "1"+result;
    }
    return result;
}
int main(){
    string num1 = "111111";
    string num2 = "999";
    string result = addStrings(num1, num2);
    cout<< result<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}

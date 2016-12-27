//
//  8-StringtoInteger(atoi).cpp
//  leecode
//
//  Created by lixiangqian on 16/12/27.
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

int myAtoi(string str) {
    long ss = str.size();
    string truestr = "";
    int s = 0;
    bool begin = false;
    for (long i = 0; i<ss; i++) {
        char tempc = str[i];
        if((tempc >='0' && tempc <='9') || (!begin && (tempc=='-' || tempc=='+'))){
            if (!begin) {
                begin = true;
            }
            //对正整数，去掉＋号
            if(tempc!='+')
                truestr += tempc;
        }else{
            if(begin || tempc!=' '){
                break;
            }
        }
    }
    string iNT_MAX = "2147483647";
    string iNT_MIN = "-2147483648";
    
    
    //处理数字字符组成的字符串
    if(ss == 0 || (truestr.size() == 1 && (truestr[0] =='-' || truestr[0] == '+'))){
        return s;
    }else{
        //和边界值比较时要比较长度和大小，对于正整数，之前去掉了＋号，现在处理会比较简单
        if((truestr[0] =='-' && (truestr.size()>=iNT_MIN.size() && truestr > iNT_MIN)) || (truestr[0] =='-' && truestr.size() > iNT_MIN.size())){
            truestr = iNT_MIN;
        }else if( (truestr.size()>=iNT_MAX.size() && truestr >iNT_MAX) || (truestr[0] != '-' && truestr.size() > iNT_MAX.size())){
            truestr = iNT_MAX;
        }
        long tlen = truestr.size()-1;
        long sindex = 0;
        if(truestr[0] == '-' || truestr[0] == '+'){
            sindex = 1;
        }
        for (; sindex <=tlen; sindex++) {
            s += pow(10, tlen-sindex)*(truestr[sindex] -'0');
        }
        if(truestr[0] == '-'){
            s = 0-s;
        }
    }
    return s;
}

int main(){
    string teststr = "   +1146905820n1";
    int testnum = myAtoi(teststr);
    cout<<testnum<<endl;
    cout<<"hello world!"<<endl;
}

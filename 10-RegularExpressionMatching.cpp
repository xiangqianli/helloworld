//
//  10-RegularExpressionMatching.cpp
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
bool isMatch(string s, string p) {
    long sl = s.size(), pl = p.size();
    bool panduan = true;
    long ss = sl-1, pp = pl-1;
    if(ss>=0 && pp>=0){
        if (p[pp]=='*') {
            if(s[ss]==p[pp-1]|| p[pp-1]=='.'){
                //注意这里不能首先把各自的值求出来，要利用或运算有true就不继续往下走。这一句话是通过最后几十个case的关键
                panduan = isMatch(s.substr(0,ss), p) || isMatch(s.substr(0,ss), p.substr(0,pp-1)) || isMatch(s, p.substr(0,pp-1));
            }else{
                panduan = isMatch(s, p.substr(0,pp-1));
            }
        }else if(p[pp]=='.'){//注意.表示必须有值
            panduan = isMatch(s.substr(0,ss), p.substr(0,pp));
        }else{
            if(p[pp]==s[ss]){
                panduan = isMatch(s.substr(0,ss), p.substr(0,pp));
            }else{
                panduan = false;
            }
        }
    //边界条件，""要与"c*b*.*.."慢慢比较
    }else if(ss == -1 && pp>=0){//s为空
        if(p[pp]=='*'){
            panduan = isMatch(s, p.substr(0,pp-1));
        }else{
            panduan = false;
        }
    }else if(pp == -1 && ss>=0){//p为空
        if(s[ss]=='*'){
            panduan = isMatch(s.substr(0, ss-1), p);
        }else{
            panduan = false;
        }
    }else{//两者都为空
        panduan = true;
    }
    return panduan;
}
int main(){
    string s = "a";
    string p = ".*..a*";
    bool panduan = isMatch(s, p);
    if(panduan){
        cout<<"hello world"<<endl;
    }else{
        cout<<"good night world"<<endl;
    }
    return 0;
}

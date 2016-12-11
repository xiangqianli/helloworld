//
//  5-LongestPalindromicSubstring.cpp
//  leecode
//
//  Created by lixiangqian on 16/12/11.
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
string longestPalindrome(string s) {
    string a = "";
    long ssize = s.size();
    if (ssize == 1) {
        return s;
    }
    long longestlength = 1;
    long longestleft = 0;
    long longestright = 0;
    for(long i=1; i<ssize; i++){
        long length=1;
        long leftnext;
        long rightnext;
        long centerleft = i;
        long centerright = i;
        bool centerfind = true;
        //从中间找相同的值
        while(centerleft >0 && centerfind){
            if(s[centerleft-1]==s[centerleft]){
                centerleft--;
                length++;
            }else{
                centerfind = false;
            }
        }
        centerfind = true;
        while(centerright < ssize-1 && centerfind){
            if(s[centerright+1]==s[centerright]){
                centerright++;
                length++;
            }else{
                centerfind = false;
            }
        }
        leftnext = centerleft -1;
        rightnext = centerright +1;
        //找两边的值
        while(leftnext >=0 && rightnext <ssize){
            if(s[leftnext]==s[rightnext]){
                length +=2;
                leftnext --;
                rightnext ++;
            }else{
                break;
            }
        }
        if(length >longestlength){
            longestlength = length;
            longestleft = leftnext+1;
            longestright = rightnext-1;
        }
    }
    a = s.substr(longestleft,longestright-longestleft+1);
    return a;
}

int main(){
    string s = "abcda";
    string r = longestPalindrome(s);
    cout<<"hello world!"<<endl;
    cout<<r<<endl;
    return 0;
}

//
//  9-PalindromeNumber.cpp
//  leetcode
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
bool isPalindrome(int x) {
    //处理小数
    if(x<0){
        return false;
    //处理个位数
    }else if(x==0 || x/10==0){
        return true;
    }else{
        bool panduan = false;
        //count the length of the Integer
        int length = 0;
        int hascountlength = 0;
        int finallength = 1;
        int tx = x;
        int y=0, z=0, yy=0;
        y=tx;
        while (y/10 != 0) {
            y = y/10;
            length ++;
        }
        length +=1;
        //存储总长度
        int totallength = length;
        while(totallength > hascountlength+1){
            y = tx;
            yy = tx;
            //从高位向地位找
            int templength = 0;
            while (y/10 != 0) {
                y = y/10;
                templength ++;
            }
            
            if(templength < length-1){
                y = 0;
            }
            //从低位向高位找
            int t = finallength;
            while(t>1){
              yy = yy/10;
              t -= 1;
            }
            z = yy%10;
            if(y==z){
                hascountlength +=2;
                tx = tx - y*pow(10, length-1) - z*pow(10,finallength-1);
                //下一步统计的个位数
                finallength +=1;
                panduan = true;
                length --;
            }else{
                panduan = false;
                break;
            }
        }
        return panduan;
    }
}
int main(){
    int x = 121;
    if(isPalindrome(x)){
        cout<<"hello world!"<<endl;
    }else{
        cout<<"good night world!"<<endl;
    }
    return 0;
}

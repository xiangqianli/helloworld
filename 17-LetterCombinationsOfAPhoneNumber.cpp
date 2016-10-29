//
//  17-LetterCombinationsOfAPhoneNumber.cpp
//  leecode
//
//  Created by lixiangqian on 16/10/27.
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
void getString(vector<string> & r,char * tr, string digits, long step, long size){
    if(step < size){
        int a = digits[step]-'0';
        char ss;
        if(a!=0&&a!=1){
            int maxx=(a-1)*3-1;
            int minn=(a-2)*3;
            if(a==7){
                maxx++;
            }else if(a==8){
                maxx++;
                minn++;
            }else if(a==9){
                maxx=maxx+2;
                minn++;
            }
            for(int i =minn; i<=maxx; i++){
                ss= 'a'+i;
                tr[step]=ss;
                getString(r,tr,digits,step+1,size);
            }
        }else if(a==0){
            ss='+';
            tr[step]=ss;
            getString(r, tr,digits, step+1, size);
        }

    }else{
        r.push_back(tr);
    }
};

vector<string> letterCombinations(string digits) {
    
    vector<string> r;
    long size = digits.size();
    if(size==0)
        return r;
    char * tr=new char[size];
    char ss;
    int a = digits[0]-'0';
    if(a!=0&&a!=1){
        int maxx=(a-1)*3-1;
        int minn=(a-2)*3;
        if(a==7){
            maxx++;
        }else if(a==8){
            maxx++;
            minn++;
        }else if(a==9){
            maxx=maxx+2;
            minn++;
        }
        for(int i =minn; i<=maxx; i++){
            ss= 'a'+i;
            tr[0]=ss;
            getString(r,tr,digits,1,size);
        }
    }else if(a==0){
        ss='+';
        tr[0]=ss;
        getString(r, tr,digits, 1, size);
    }
    return r;
}
int main(){
    
    vector<string> r = letterCombinations("7");
    for(int i=0; i<r.size(); i++){
        cout<<"========"<<endl;
        cout<<r[i]<<endl;
    }
    return 0;
}

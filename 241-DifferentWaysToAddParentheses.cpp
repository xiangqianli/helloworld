//
//  241diffWaysToCompute.cpp
//  leecode
//
//  Created by lixiangqian on 16/10/26.
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
struct l{
    vector<int> left;
    vector<int> right;
    string symbol;
};
vector<int> diffWaysToCompute(string input){
    long size = input.size();
    vector<int> r;
    //注意数字不一定是个位数；string的find函数，里面的字符要用""括起来不能用''，若没有找到则会返回2^64-1，为－1的值，所以只能判断是否==-1，不能判断是否>0
    if(input.find("+")==-1&&input.find("-")==-1&&input.find("*")==-1)
        r.push_back(atof(input.c_str()));
    else
        for(long i=min(min(input.find_first_of("+")!=-1?input.find_first_of("+"):size,input.find_first_of("-")!=-1?input.find_first_of("-"):size),input.find_first_of("*")!=-1?input.find_first_of("*"):size);i<size;){
            int start = 0;
            int end = (int)size-1;
            l* top = new l();
            top->symbol = input[i];
            top->left=diffWaysToCompute(input.substr(0,i-start));
            top->right=diffWaysToCompute(input.substr(i+1,end-i));
            for(int k=0;k<top->left.size();k++){
                int leftvalue = top->left[k];
                for(int m=0;m<top->right.size();m++){
                    int rightvalue = top->right[m];
                    int tempr = input[i]=='*'?leftvalue*rightvalue:input[i]=='+'?(leftvalue+rightvalue):input[i]=='-'?(leftvalue-rightvalue):0;
                    r.push_back(tempr);
                }
            }
            i=min(min(input.find("+",i+1)!=-1?input.find("+",i+1):size,input.find("-",i+1)!=-1?input.find("-",i+1):size),input.find("*",i+1)!=-1?input.find("*",i+1):size);
        }
    return r;

}
int main(){
    string s = "2*3-41*5";
    vector<int> r = diffWaysToCompute(s);
    for(int i=0;i<r.size();i++){
        cout<<r[i]<<endl;
    }
    return 0;
}

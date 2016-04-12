#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdlib.h>
using namespace std;
int resultCount=0;
vector< vector<int> > anotherList;
vector<long long> resultList;
bool ok(long long tempNum){
    int i,j=2,v = 0;
    bool returnNum=true;
    long long myNum;
    vector<int> anList;
    for(i=2;i<=10;i++){
        for(j=2;j<=1000;j++){
            v=0;
            myNum=tempNum;
            while(myNum){
                v=(v*i+myNum%2)%j;
                myNum/=2;
            }
            if(v==0)
                break;
        }
        if(v==1||j==1001)
            return false;
        else
            anList.push_back(j);
    }
    anotherList.push_back(anList);
    return returnNum;
}
int main() {
    int sumCount,x,y=0;
    FILE *fp=fopen("/Users/lxq/Downloads/C-large-practice.in.txt","r");
    FILE *fw=fopen("/Users/lxq/Downloads/C-large-practice.out.txt","w");
    if (fp) {
        fscanf(fp,"%d",&sumCount);
        for (int j=0; j<sumCount; j++) {
            fscanf(fp,"%d %d\n",&x,&y);
            resultCount=y;
            for (long long tempResult=(1LL<<(x-1))+1; resultCount>0; tempResult+=2) {
                if(ok(tempResult)){
                    resultList.push_back(tempResult);
                    resultCount--;
                }
            }
        }
    }
    for (int i=0; i<sumCount; i++){
        fprintf(fw,"Case #%d:\n",i+1);
        for (int j=0; j<y; j++) {
            long long string=resultList[i*y+j];
            //itoa(resultList[i*y+j],string,2);
            while(string){
                fprintf(fw,"%lld",string%2);
                string/=2;
            }
            fprintf(fw, " ");
            for (int k=0; k<8; k++)
                fprintf(fw,"%d ", anotherList[i*y+j][k]);
            fprintf(fw,"%d\n", anotherList[i*y+j][8]);
        }
    }
    return 0;
}

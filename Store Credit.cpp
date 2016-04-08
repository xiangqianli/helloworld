#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//string largePath="/Users/lxq/Downloads/A-large-practice.in.txt";

typedef struct {
    int firstNum;
    int secondNum;
}resultNum;
int main() {
    // insert code here...
    vector<int> creditInStore;
    vector<resultNum> resultList;
    int sumCount;
    int credit;
    int indexCount;
    int anotherNum=0;
    bool hasFind;
    resultNum myResult;
    FILE *fp=fopen("/Users/lxq/Downloads/A-large-practice.in.txt","r");
    FILE *fw=fopen("/Users/lxq/Downloads/A-large-practice.out.txt","w");

    if (fp) {
    fscanf(fp,"%d",&sumCount);
    for (int j=0; j<sumCount; j++) {
        fscanf(fp,"%d",&credit);
        fscanf(fp,"%d",&indexCount);
        int tempNum;
        hasFind=false;
        vector<int>::iterator it;
        for (int i=0; i<indexCount; i++) {
            fscanf(fp,"%d",&tempNum);
            creditInStore.push_back(tempNum);
        }
        int i=0;
        //找符合条件的两个数，判断不重复和找的到即可，不用排序
        for (; i<indexCount; i++) {
            tempNum=creditInStore[i];
            it= find(creditInStore.begin(), creditInStore.end(), (credit-tempNum));
            if (it!=creditInStore.begin()+i&&it!=creditInStore.end()){
                anotherNum=it-creditInStore.begin();
                tempNum=min(i,anotherNum);
                anotherNum=max(i,anotherNum);
                i=tempNum;
            }
            else
                continue;
            hasFind=true;
            break;
        }
        if (hasFind==true) {
            myResult.firstNum=i+1;
            myResult.secondNum=anotherNum+1;
            resultList.push_back(myResult);
        }
        creditInStore.clear();
    }
    }
    for (int i=0; i<sumCount; i++)
        fprintf(fw,"Case #%d: %d %d\n",i+1,resultList[i].firstNum,resultList[i].secondNum);
    return 0;
}

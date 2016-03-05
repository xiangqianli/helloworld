//
//  main.cpp
//  leecode
//  又一道深度优先遍历的题目，前期搞清楚题目要求用了很长时间：给出的所有[from,to]都能连成串，以及可能会发生回溯,可能有重复的[from,to]串。
//  map可以边insert边排序，如果有重复的[from,to]串，加一个串到个数的映射。
//  Created by lxq on 16/3/3.
//  Copyright (c) 2016年 lxq. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
    vector<string> resultList;
    map<string,map<string, int>> nodeList;
    map<string, bool> finishOrNot;

public:
    vector<string> findItinerary(vector<pair<string,string>> tickets){
        long long length=tickets.size();
        string fromString,toString;
        map<string, int> tempList;
                //创建邻接链表
        for (int i=0;i<length;i++) {
            fromString=tickets[i].first;
            toString=tickets[i].second;
            map<string, map<string, int>>::iterator fromStringIt=nodeList.find(fromString);
            if (nodeList.size()==0||fromStringIt==nodeList.end()) {
                tempList.clear();
                tempList.insert(pair<string, int>(toString,1));
                nodeList.insert(pair<string,map<string, int>>(fromString,tempList));
                finishOrNot.insert(pair<string, bool>(fromString,false));
            }else {
                map<string, int>::iterator toStringIt=fromStringIt->second.find(toString);
                if (toStringIt!=fromStringIt->second.end()) {
                    toStringIt->second++;
                }else
                    fromStringIt->second.insert(pair<string, int>(toString,1));
            }
        }
        //搜索
        fromString="JFK";
        resultList.push_back(fromString);
        stringSearch(fromString,length);
        return resultList;
    }
    int stringSearch(string fromString,long long length){
        map<string,map<string, int>>::iterator stringLead=nodeList.find(fromString);
        if (length==0) {//由错误用例推出，当fromString不存在，但长度为0时，依然成立
            return 1;
        }else if(stringLead==nodeList.end()){
            return 2;
        }
        map<string, int> stringList=stringLead->second;
        map<string, int>::iterator stringScan;
        int temp=2;
        for (stringScan=stringList.begin();stringScan!=stringList.end();stringScan++) {
            if (stringScan->second>0) {
                resultList.push_back(stringScan->first);
                stringScan->second--;
                length--;
                stringLead->second=stringList;
                temp=stringSearch(stringScan->first,length);
                if (temp==2) {
                    resultList.pop_back();
                    stringScan->second++;
                    length++;
                    stringLead->second=stringList;
                }else
                    break;
            }
        }
        if(length==0){
            return 1;
        }else if(stringScan==stringList.end()){
            return 2;
        }else{
            return temp;
        }
    }
};
int main(int argc, const char * argv[]) {
    vector<pair<string,string>> tickets;
    /*
    tickets.push_back(pair<string, string>("JFK","KUL"));
    tickets.push_back(pair<string, string>("JFK","NRT"));
    tickets.push_back(pair<string, string>("NRT","JFK"));
    */
    tickets.push_back(pair<string, string>("MUC","LHR"));
    tickets.push_back(pair<string, string>("JFK","MUC"));
    tickets.push_back(pair<string, string>("SFO","SJC"));
    tickets.push_back(pair<string, string>("LHR","SFO"));

    /*这是Solution中指出的错误用例，原用例长度约为43，出错点在38之后的位置，即以下序列，从EZE开始
    tickets.push_back(pair<string, string>("EZE","HBA"));
    tickets.push_back(pair<string, string>("EZE","OOL"));
    tickets.push_back(pair<string, string>("OOL","JFK"));
    tickets.push_back(pair<string, string>("OOL","EZE"));
    tickets.push_back(pair<string, string>("JFK","OOL"));
    tickets.push_back(pair<string, string>("EZE","TIA"));
    tickets.push_back(pair<string, string>("TIA","EZE"));
     */

        Solution sol;
    vector<string> result=sol.findItinerary(tickets);
    for(int x=0;x<result.size();x++){
        cout<<result[x]<<" ";
    }
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

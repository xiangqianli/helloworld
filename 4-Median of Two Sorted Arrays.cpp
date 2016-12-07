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
int min(int a, int b){
	return a>b?b:a;
}
double findmedian(vector<int>& nums1, vector<int>& nums2, long start1, long length1, long start2, long length2, long place){
	if(length2<length1){
		return findmedian(nums2,nums2,start2,length2,start1,length1,place);
	}
	if(length1 <=0){
		return nums2[start2+place-1];
	}
	long pa = min(place/2,length1);
	long pb = place - pa;
	if(nums1[start1+pa-1]<nums2[start2+pb-1]){
		return findmedian(nums1,nums2,start1+pa,length1-pa,start2,length2,place-pa);
	}else{
		return findmedian(nums1,nums2,start1,length1,start2+pb,length2-pb,place-pb);
	}
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    long s1 = nums1.size();
	long s2 = nums2.size();
	long k = s1+s2;
	bool isodd = true;
	if((s1+s2)%2==0){
		return (findmedian(nums1,nums2,0,s1,0,s2,k/2)+findmedian(nums1,nums2,0,s1,0,s2,1+k/2))/2;
	}else{
		return findmedian(nums1,nums2,0,s1,0,s2,(k+1)/2);
	}
}
int main(){
	vector<int> nums1(3);
	nums1[0]=1;
	nums1[1]=3;
	nums1[2]=6;

	vector<int> nums2(4);
	nums2[0]=3;
	nums2[1]=5;
	nums2[2]=9;
	nums2[3]=10;
	double r = findMedianSortedArrays(nums1,nums2);
	cout<<"hello world!"<<endl;
	cout<<r<<endl;
	return 0;
}

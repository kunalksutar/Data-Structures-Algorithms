#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(vector<int>&nums,int left,int mid,int right,int &ans){
    int j=mid+1;//j through right array
    for(int i=left;i<=mid;i++){//i through the left array
        long long left_num=nums[i];
        long long right_num=(long long)2*nums[j];
        while(left_num>right_num && j<=right){
            j++;
            right_num=(long long)2*nums[j];
        }
        ans+=j-mid-1;
    }sort(nums.begin()+left,nums.begin()+right+1);
}

void mergeSort(vector<int>&nums,int left,int right,int &ans){
    if(left==right)return;
    int mid=left+(right-left)/2;
    mergeSort(nums,left,mid,ans);
    mergeSort(nums,mid+1,right,ans);
    merge(nums,left,mid,right,ans);
}

int reversePairs(vector<int>&nums){
    int ans=0;
    mergeSort(nums,0,nums.size()-1,ans);
    return ans;
}
int main(){
vector<int>vec={-5,-5};
cout<<reversePairs(vec);
return 0;
}
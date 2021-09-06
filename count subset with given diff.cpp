#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[]={1,1,3,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	int s=0;
	for(int i=0;i<n;i++)
		s+=arr[i];
	int diff=1;
	int sum=(diff+s)/2;
	int t[n+1][sum+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(i==0)
				t[i][j]=0;
			if(j==0)
				t[i][j]=1;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(arr[i-1]>j)
				t[i][j]=t[i-1][j];
			else
				t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
		}
	}
	cout<<t[n][sum];		
}

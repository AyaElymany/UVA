#include<bits/stdc++.h>
using namespace std;

int x,vis[10][1000],w[10][1000];

int solve(int alt,int idx){
	if(alt>9||alt<0)return 1000000;
	if((idx==x-1)&&(alt==9))return 0;
	if(idx==x-1)return 1000000;
	if(vis[alt][idx]!=-1)return vis[alt][idx];
	vis[alt][idx]=solve(alt-1,idx+1)+60-w[alt][idx+1];
	vis[alt][idx]=min(solve(alt,idx+1)+30-w[alt][idx+1],vis[alt][idx]);
	vis[alt][idx]=min(solve(alt+1,idx+1)+20-w[alt][idx+1],vis[alt][idx]);
	return vis[alt][idx];
}

int main(){
	int t,ans;
	scanf("%d",&t);
	while(t--){
		memset(vis,-1,sizeof vis);
		scanf("%d",&x);
		x/=100;
		for(int i=0;i<10;i++)
			for(int j=0;j<x;j++)
				scanf("%d",&w[i][j]);
		ans=min(solve(9,0)+30-w[9][0],solve(8,0)+60-w[9][0]);
		printf("%d\n\n",ans);
	}
}

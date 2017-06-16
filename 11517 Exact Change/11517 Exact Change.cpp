#include<bits/stdc++.h>
using namespace std;

int n,a[100],p,vis[100][10001],num[100][10001];

pair<int,int>solve(int idx,int v){
	if(v>=p)return make_pair(v,0);
	if(idx==n) return make_pair(1000000,0);
	if(vis[idx][v]!=-1)return make_pair(vis[idx][v],num[idx][v]);
	pair<int,int >p1=solve(idx+1,v);
	pair<int,int >p2=solve(idx+1,v+a[idx]);
	if((p1.first<p2.first)||((p1.first==p2.first)&&(p1.second<=p2.second)))
		vis[idx][v]=p1.first,num[idx][v]=p1.second;
	else vis[idx][v]=p2.first,num[idx][v]=p2.second+1;

	return make_pair(vis[idx][v],num[idx][v]);
}

int main(){
	//freopen("DataSet.txt","r",stdin);
	int t;
	pair<int,int>ans;
	scanf("%d",&t);
	while(t--){
		memset(vis,-1,sizeof vis);
		scanf("%d%d",&p,&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		ans=solve(0,0);
		printf("%d %d\n",ans.first,ans.second);
	}
}

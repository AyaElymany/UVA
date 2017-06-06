#include<bits/stdc++.h>
using namespace std;

int m,s,a[40],b[40],vis[40][301][301];

int solve(int idx,int x,int y){
	if(x*x+y*y==s*s)return 0;
	if(idx==m||x*x+y*y>s*s)return 1000;
	if(vis[idx][x][y]!=-1)return vis[idx][x][y];
	return vis[idx][x][y]=min(solve(idx,x+a[idx],y+b[idx])+1,solve(idx+1,x,y));
}

int main(){
	int t,ans;
	scanf("%d",&t);
	while(t--){
		memset(vis,-1,sizeof vis);
		scanf("%d%d",&m,&s);
		for(int i=0;i<m;i++)
			scanf("%d%d",&a[i],&b[i]);
		ans=solve(0,0,0);
		if(ans<1000)printf("%d\n",ans);
		else puts("not possible");
	}
}

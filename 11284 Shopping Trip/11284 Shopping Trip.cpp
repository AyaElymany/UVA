#include<bits/stdc++.h>
using namespace std;

int n,p,x[13];
double dis[51][51],dp[13][8192],c[13];
bool vis[13][8192];

void initial(){
	for(int i=0;i<51;i++)
		for(int j=0;j<51;j++)
			if(i==j)dis[i][j]=0;
			else dis[i][j]=1e10;
	for(int i=0;i<13;i++)
		for(int j=0;j<8192;j++)
			vis[i][j]=0;
}

void warshal(){
	for(int k=0;k<=n;k++)
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++){
				if(i==j||i==k||j==k)continue;
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
			}
}

double solve (int idx, int info){
	if(info==((1<<p)-1))return dis[x[idx]][0];
	if(vis[idx][info])return dp[idx][info];
	vis[idx][info]=1;
	double ret=1e18;
	for(int i=0;i<p;i++)
		if(!(info&(1<<i)))
			ret=min(ret,min(solve(i,info+(1<<i))+dis[x[idx]][x[i]],solve(idx,info+(1<<i))+c[i]));
	return dp[idx][info]=ret;
}
int main(){
	int t,m,a,b;
	double d,v,sum;
	scanf("%d",&t);
	while(t--){
		initial();
		sum=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d%d%lf",&a,&b,&d);
			dis[a][b]=dis[b][a]=min(dis[a][b],d);
		}
		scanf("%d",&p);
		p++;
		for(int i=1;i<p;i++)
			scanf("%d%lf",&x[i],&c[i]),sum+=c[i];
		warshal();
		v=solve(0,1);
		if(sum-v>=.005)printf("Daniel can save $%.2lf\n",sum-v);
		else puts("Don't leave the house");
	}
}

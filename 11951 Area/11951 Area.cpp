#include<bits/stdc++.h>
using namespace std;

int main(){
	int T,n,m,K,a[101][101],area,cost,cur_area,cur_cost;
	memset(a,0,sizeof a);
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		area=cost=0;
		scanf("%d%d%d",&n,&m,&K);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				a[i][j]+=(a[i][j-1]+a[i-1][j]-a[i-1][j-1]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				for(int k=i;k<=n;k++)
					for(int l=j;l<=m;l++){
						cur_cost=a[k][l]-a[k][j-1]-a[i-1][l]+a[i-1][j-1];
						cur_area=(k-i+1)*(l-j+1);
						if(((cur_cost<=K)&&(cur_area>area))||((cur_area==area)&&(cur_cost<cost)))
							area=cur_area,cost=cur_cost;
					}
		printf("Case #%d: %d %d\n",t,area,cost);
	}
}

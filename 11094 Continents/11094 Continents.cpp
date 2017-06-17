#include<bits/stdc++.h>
using namespace std;

char g[20][21],l;
int m,n,vis[20][20];

int fill(int x,int y,int flag){
	if(x==m||x<0)
		return 0;
	if(y<0)y+=n;
	if(y==n)y=0;
	if(vis[x][y]!=-1||g[x][y]!=l)
		return 0;
	vis[x][y]=flag;
	return 1+fill(x,y+1,flag)+fill(x,y-1,flag)+fill(x+1,y,flag)+fill(x-1,y,flag);
}

int main(){
	int x,y,ans,cnt;
	while(scanf("%d",&m)==1){
		cnt=ans=0;
		memset(vis,-1,sizeof vis);
		scanf("%d",&n);
		for(int i=0;i<m;i++){
			getchar();
			for(int j=0;j<n;j++)
				g[i][j]=getchar();
		}
		scanf("%d%d",&x,&y);
		l=g[x][y];
		fill(x,y,cnt++);
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(g[i][j]==l&&vis[i][j]==-1)
					ans=max(ans,fill(i,j,cnt++));
		printf("%d\n",ans);
	}
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t=1,l,u,r,b[10],vis[10000],cur;
	queue<int> q;
	while(scanf("%d%d%d",&l,&u,&r)&&r){
		memset(vis,-1,sizeof vis);
		for(int i=0;i<r;i++)
      scanf("%d",&b[i]);
		vis[l]=0;
		q.push(l);
		while(q.size()){
			l=q.front();
			q.pop();
			for(int i=0;i<r;i++){
				cur=(l+b[i])%10000;
				if(vis[cur]==-1){
					q.push(cur);
						vis[cur]=vis[l]+1;
				}
			}
		}
		(vis[u]!=-1)?printf("Case %d: %d\n",t++,vis[u]):printf("Case %d: Permanently Locked\n",t++);
	}
}

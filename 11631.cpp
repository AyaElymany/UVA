#include<bits/stdc++.h>
using namespace std;
int p[200000],sz[200000];
struct road{
	int x,y,len;
};
bool cmp(road b,road a){
	if(a.len==b.len){
		if(b.x==a.x)return b.y<a.y;
		return (b.x<a.x);
	}
	return b.len<a.len;
}
int parent(int x){
	return(x==p[x])?x:p[x]=parent(p[x]);
}
void join(int x,int y){
	if(sz[x]>=sz[y])
		sz[x]+=sz[y],p[y]=x;
	else
		sz[y]+=sz[x],p[x]=y;
}
road r[200000];
int main(){
	int n,m,sum,px,py,token;

	while(scanf("%d%d",&n,&m)&&n){
		token=sum=0;
		for(int i=0;i<n;i++)p[i]=i,sz[i]=0;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&r[i].x,&r[i].y,&r[i].len),sum+=r[i].len;
		}
		sort(r,r+m,cmp);
		for(int i=0;token<(n-1)&&i<m;i++){
			px=parent(r[i].x);
			py=parent(r[i].y);
			if(px!=py)join(py,px),token++,sum-=r[i].len;
		}
		printf("%d\n",sum);
	}
}

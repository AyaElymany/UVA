#include<bits/stdc++.h>
using namespace std;
struct interval{
	int s,e;
};
int main(){
	map<int,int>idx;
	int n,m,x,y,cnt;
	interval a[10000],b[100];
	set<int>time;
	while(scanf("%d%d",&n,&m)&&n){
		for(int i=0;i<n;i++){
			scanf("%d%d%d%d",&x,&y,&a[i].s,&a[i].e);
			a[i].e+=a[i].s-1;
		}
		for(int i=0;i<m;i++){
			scanf("%d%d",&b[i].s,&b[i].e);
			b[i].e+=b[i].s-1;
		}

			for(int j=0;j<m;j++){
				cnt=0;
				for(int i=0;i<n;i++)
				if((a[i].s>=b[j].s && a[i].s<=b[j].e)||(a[i].e>=b[j].s&&a[i].e<=b[j].e)||(b[j].s>=a[i].s&&b[j].s<=a[i].e)||(b[j].e>=a[i].s&&b[j].e<=a[i].e))
					cnt++;
				printf("%d\n",cnt);
			}
	}
}

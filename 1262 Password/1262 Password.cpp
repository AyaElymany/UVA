#include<bits/stdc++.h>
using namespace std;
char g[6][6];
int num[5];
set<string>password;
set<string>::iterator it;
void solve(int idx,string s){
	if(idx==5){password.insert(s); return ;}
	char cur[6];
	for(int i=0;i<idx;i++)cur[i]=s[i];
	for(int i=0;i<num[idx];i++){
		cur[idx]=g[idx][i];
		solve(idx+1,cur);
	}
}
int main(){
	unsigned int t,k;
	char g1[6][6],g2[6][6];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		password.clear();
		memset(num,0,sizeof num);
		for(int i=0;i<6;i++)scanf("%s",g1[i]);
		for(int i=0;i<6;i++)scanf("%s",g2[i]);
		for(int j=0;j<5;j++)
			for(int i=0;i<6;i++)
				for(int k=0;k<6;k++)
					if(g1[i][j]==g2[k][j])
						g[j][num[j]++]=g1[i][j],k=6;
		solve(0,"");
		if(k>password.size())puts("NO");
		else{
			it=password.begin();
			advance(it,k-1);
			string s=*it;
			cout<<*it<<"\n";
		}
	}
}

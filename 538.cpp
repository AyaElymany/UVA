#include<bits/stdc++.h>
using namespace std;
struct account{
	int i,v;
};
struct accoun{
	int i,v;
};
bool operator <(account b,account a){
	if(b.v==a.v)return b.i<a.i;
	return b.v<a.v;
}
bool operator <(accoun b, accoun a){
	if(b.v==a.v)return b.i<a.i;
	return b.v>a.v;
}
int main(){
	int t=1,n,x,acc[21],temp;
	map<string,int>idx;
	map<int,string>names;
	char name1[1000],name2[1000];
	set<account>neg;
	set<accoun>pos;
	set<account>::iterator it;
	account a,ne;
	accoun po;
	while(scanf("%d%d",&n,&x)&&n){
		pos.clear(),neg.clear(),names.clear(),idx.clear();
		for(int i=1;i<=n;i++){
			scanf("%s",name1);
			idx[name1]=i;
			names[i]=name1;
		}
		memset(acc,0,sizeof acc);
		while(x--){
			scanf("%s%s%d",name1,name2,&temp);
			acc[idx[name2]]+=temp;
			acc[idx[name1]]-=temp;
		}
		for(int i=1;i<=n;i++){
			po.i=i,po.v=acc[i];
			a.i=i,a.v=acc[i];
			if(acc[i]>0)
				pos.insert(po);
			else if (acc[i]<0)neg.insert(a);
		}
		printf("Case #%d\n",t++);
		while(neg.size()){
			po=*pos.begin();
			pos.erase(pos.begin());
			ne=*neg.begin();
			neg.erase(neg.begin());
			if(po.v>=abs(ne.v)){
				printf("%s %s %d\n",names[po.i].c_str(),names[ne.i].c_str(),abs(ne.v));
				po.v+=ne.v;
				if(po.v)pos.insert(po);
			}
			else{
				printf("%s %s %d\n",names[po.i].c_str(),names[ne.i].c_str(),po.v);
				ne.v+=po.v;
				neg.insert(ne);
			}
		}
		puts("");
	}
}

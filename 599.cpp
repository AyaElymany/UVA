#include<bits/stdc++.h>
using namespace std;
int p[26],size[26];
int parent(int x){
	return p[x]=((p[x]==x)?x:parent(p[x]));
}
void join(int a,int b){
	int p1=parent(a),p2=parent(b);
	size[p1]+=size[p2];
	p[p2]=p1;
}
int main(){
	int t,tree,acron,len;
	char line[52];
	bool is_node[26];
	scanf("%d",&t);
	while(t--){
		tree=acron=0;
		for(int i=0;i<26;i++)
			p[i]=i,size[i]=1;
		memset(is_node,0,sizeof(is_node));
		scanf("%s",line);
		while(line[0]!='*'){
			join(line[1]-'A',line[3]-'A');
			scanf("%s",line);
		}
		scanf("%s",line);
		len=strlen(line);
		for(int i=0;i<len;i+=2)
			is_node[line[i]-'A']=1;
		for(int i=0;i<26;i++){
			if(is_node[i]&&(parent(p[i])==i)){
				if(size[i]>1)tree++;
				else acron++;
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n",tree,acron);
	}
}

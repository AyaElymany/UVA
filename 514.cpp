#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,idx,order[1000];
	stack<int>s;
	bool can;
	while(scanf("%d",&n)&&n){
		while(scanf("%d",&order[0])&&order[0]){
			for(int i=1;i<n;i++)
				scanf("%d",&order[i]);
			idx=1;
			can=1;
			while(s.size())s.pop();
			for(int i=0;i<n;i++){
				if( (order[i]<idx) && ((!(s.size())) ||(s.top()!=order[i])) )
					puts("No"),i=n,can=0;
				else if(s.size()&&s.top()==order[i])
					s.pop();
				else{
					while(idx<order[i])s.push(idx++);
					idx++;
				}
			}
			if(can)puts("Yes");
		}
		puts("");
	}
}

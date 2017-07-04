#include<bits/stdc++.h>
using namespace std;
int main()
{
	int w,b,a[20],temp,t=1,min_num,mx,profit,idx;
	vector<int>prob[50];
	bool f[1001];
	while(scanf("%d",&w)&&w){
		//if(t==11)break;
		if(t>1)puts("");
		min_num=profit=0;
		for(int k=0;k<w;k++){
			scanf("%d",&b);
			if(b){
				scanf("%d",&temp);
				idx=0,mx=a[0]=10-temp;
				for(int i=1;i<b;i++)scanf("%d",&temp),a[i]=a[i-1]+10-temp,mx=max(mx,a[i]);
				for(int i=0;i<b;i++)if(a[i]==mx)idx=i,i=b;
				if(mx>0)min_num+=idx+1,profit+=mx;
				else if(!mx) {
					for(int i=0;i<b;i++)if(a[i]==mx)prob[k].push_back(i+1);
				}
				if(mx>0)for(int i=idx+1;i<b;i++)if(a[i]==mx)prob[k].push_back(i-idx);
			}
		}
		memset(f,0,sizeof f);
		f[min_num]=1;
		for(int k=0;k<w;k++){
			for(int i=1000;i>=0;i--)
				if(f[i])
					for(int j=0;j<(int)prob[k].size();j++)
						if(i+prob[k][j]<1001)f[i+prob[k][j]]=1;
			prob[k].clear();
		}

		printf("Workyards %d\nMaximum profit is %d.\nNumber of pruls to buy:",t++,profit);
		temp=0;
		for(int i=min_num;(temp<10)&&(i<1001);i++)
			if(f[i])printf(" %d",i),temp++;
		puts("");
	}
}

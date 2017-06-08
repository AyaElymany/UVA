#include<bits/stdc++.h>
using namespace std;
int n,a[76][76];
int calc(int i,int j,int k,int l){
	int A=a[i-1][j-1];
	int B=a[i-1][l];
	int C=a[k][j-1];
	int D=a[k][l];
	int E=a[n][j-1];
	int F=a[i-1][n];
	int G=a[n][n];
	int H=a[k][n];
	int J=a[n][l];
	int ret=D+A-B-C;
	ret=max(ret,G-H-J+D+E-C+F-B+A);
	ret=max(ret,J-D-E+C+B-A);
	ret=max(ret,H-D-F+B+C-A);
	return ret;
}
int main(){
	int t,ans;
	scanf("%d",&t);
	while(t--){
		ans=-1000000;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]+=(a[i][j-1]+a[i-1][j]-a[i-1][j-1]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=i;k<=n;k++)
					for(int l=j;l<=n;l++)
						ans=max(ans,calc(i,j,k,l));
		printf("%d\n",ans);
	}
}

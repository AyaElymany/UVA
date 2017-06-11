#include<bits/stdc++.h>
using namespace std;

int n,m;
char c;
bool a[201][201];

void printnm(){
	if(n<10)printf("   %d",n);
	else if(n<100)printf("  %d",n);
	else printf(" %d",n);
	if(m<10)printf("   %d\n",m);
	else if(m<100)printf("  %d\n",m);
	else printf(" %d\n",m);
}

void readB(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%c",&c);
			if(c=='\n')scanf("%c",&c);
			if(c=='1')a[i][j]=1;
			else a[i][j]=0;
		}
	}
}

void readD(int rs,int re,int cs,int ce){
	if(rs>re||cs>ce)return;
	scanf("%c",&c);
	if(c=='\n')scanf("%c",&c);
	if(c=='D'){
		readD(rs,(rs+re)/2,cs,(cs+ce)/2);
		readD(rs,(rs+re)/2,(cs+ce)/2+1,ce);
		readD((rs+re)/2+1,re,cs,(cs+ce)/2);
		readD((rs+re)/2+1,re,(cs+ce)/2+1,ce);
		return;
	}
	if(c=='1'){
		for(int i=rs;i<=re;i++)
			for(int j=cs;j<=ce;j++)
				a[i][j]=1;
		return;
	}
	for(int i=rs;i<=re;i++)
		for(int j=cs;j<=ce;j++)
			a[i][j]=0;
}

void outB(){
	printf("B");
	printnm();
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			printf(a[i][j]?"1":"0");
			cnt++;
			if(!(cnt%50)&&(i<n||j<m))puts("");
		}
	puts("");
}

string outD(int rs,int re,int cs,int ce){
	if(rs>re||cs>ce)return "";
	if(rs==re&&cs==ce)return a[rs][cs]?"1":"0";
	string q1,q2,q3,q4;
	q1=outD(rs,(rs+re)/2,cs,(cs+ce)/2);
	q2=outD(rs,(rs+re)/2,(cs+ce)/2+1,ce);
	q3=outD((rs+re)/2+1,re,cs,(cs+ce)/2);
	q4=outD((rs+re)/2+1,re,(cs+ce)/2+1,ce);

	int s1=q1.size(),s2=q2.size(),s3=q3.size(),s4=q4.size();

	if((s1==1)&&(((s2==1)&&(q1[0]==q2[0]))||(!s2))&&(((s3==1)&&(q1[0]==q3[0]))||(!s3))&&(((s4==1)&&(q1[0]==q4[0]))||(!s4)))
		return q1;
	string ret="D";
	ret+=q1;
	ret+=q2;
	ret+=q3;
	ret+=q4;
	return ret;
}

int main(){
	char type;
	string d;
	int s,cnt;
	while(scanf("%c",&type)&&type!='#'){
		scanf("%d%d\n",&n,&m);
		if(type=='B'){
			readB(),printf("D"),printnm();
			d=outD(1,n,1,m);
			s=d.size();
			cnt=0;
			for(int i=0;i<s;i++){
				printf("%c",d[i]);
				cnt++;
				if(!(cnt%50)&&(i+1<s))puts("");
			}
			puts("");
		}
		else readD(1,n,1,m),outB();
		scanf("\n");
	}
}

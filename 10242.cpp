#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("in.txt","r",stdin);
	double x,y,m1,m2,x1,x2,x3,y1,y2,y3,x4,y4,X1,X2,Y1,Y2;
	while(scanf("%lf",&x1)==1){
		scanf("%lf%lf%lf%lf%lf%lf%lf",&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		(y1==y3||y1==y4)?(X1=x2,Y1=y2):(X1=x1,Y1=y1);
		(y3==y1||y3==y2)?(X2=x4,Y2=y4):(X2=x3,Y2=y3);
		if(x2==x1){
			m2=(y4-y3)/(x4-x3);
			(x3==x1)?x=x4:x=x3;
			y=m2*x-m2*X1+Y1;
		}
		else if(x3==x4){
			m1=(y2-y1)/(x2-x1);
			(x1==x3)?x=x2:x=x1;
			y=m1*x-m1*X2+Y2;
		}
		else{
			m1=(y2-y1)/(x2-x1);
			m2=(y4-y3)/(x4-x3);
			x=(m1*X2-Y2-m2*X1+Y1)/(m1-m2);
			y=m2*x-m2*X1+Y1;
		}
		printf("%.3lf %.3lf\n",x,y);
	}
}

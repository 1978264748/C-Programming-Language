#include <stdio.h>
#include <math.h>
int main(){
	double a[4];
	int f=0,err=0,op1,op2,op3,i;
	double x1,x2,x3,eps=1e-7;
	double sum;
	int m[4];
	for(i=0;i<4;i++){
		scanf("%lf",&a[i]);
	}
	for(m[0]=0;m[0]<4;m[0]++){
		for(m[1]=0;m[1]<4;m[1]++){
			if(m[1]==m[0])continue;
			for(m[2]=0;m[2]<4;m[2]++){
				if(m[2]==m[1]||m[2]==m[0])continue;
					for(m[3]=0;m[3]<4;m[3]++){
						if(m[3]==m[2]||m[3]==m[1]||m[3]==m[0])continue;
							for(op1=1;op1<=4;op1++){  //op1-->op2-->op3  ((op1)op2)op3
								for(op2=1;op2<=4;op2++){	
									for(op3=1;op3<=4;op3++){ 
										sum=a[m[0]];
										i=1;
										err=0;
									switch(op1){
										case 1:
											sum+=a[m[i]];
											i++;
											break;
										case 2:
											sum-=a[m[i]];
											i++;
											break;
										case 3 :
											sum*=a[m[i]];
											i++;
											break;
										case 4 :
											if(a[m[i]]==0){
												err=1;
												break;
											}
											else{
												sum/=a[m[i]];
												i++;
												break;
											}			
									}
									switch(op2){
										case 1 :
											sum+=a[m[i]];
											i++;
											break;
										case 2 :
											sum-=a[m[i]];
											i++;
											break;
										case 3 :
											sum*=a[m[i]];
											i++;
											break;
										case 4 :
											if(a[m[i]]==0){
												err=1;
												break;
											}
											else{
												sum/=a[m[i]];
												i++;
												break;
											}			
									}
									switch(op3){
										case 1 :
											sum+=a[m[i]];
											i++;
											break;
										case 2 :
											sum-=a[m[i]];
											i++;
											break;
										case 3 :
											sum*=a[m[i]];
											i++;
											break;
										case 4 :
											if(a[m[i]]==0){
												err=1;
												break;
											}
											else{
												sum/=a[m[i]];
												i++;
												break;
											}			
									}
										if(err==1)continue;
										if(fabs(sum-24)<eps&&f==0){
											printf("((%.0lf",a[m[0]]);
											switch(op1){
												case 1 :
													printf("+");
													break;
												case 2 :
													printf("-");
													break;
												case 3 :
													printf("*");
													break;
												case 4 :
													printf("/");
													break;
											}
											printf("%.0lf)",a[m[1]]);
											switch(op2){
												case 1 :
													printf("+");
													break;
												case 2 :
													printf("-");
													break;
												case 3 :
													printf("*");
													break;
												case 4 :
													printf("/");
													break;
											}
											printf("%.0lf)",a[m[2]]);
											switch(op3){
												case 1 :
													printf("+");
													break;
												case 2 :
													printf("-");
													break;
												case 3 :
													printf("*");
													break;
												case 4 :
													printf("/");
													break;
											}
											printf("%.0lf\n",a[m[3]]);
											f=1;
											}
									}
								}
							}
							for(op1=1;op1<=4;op1++){  //op1-->op3-->op2&&op3-->op1-->op2  ( op1 )op2( op3 ) 
								for(op2=1;op2<=4;op2++){	
									for(op3=1;op3<=4;op3++){
										err=0;
										sum=0;
									switch(op1){
										case 1:
											x1=a[m[0]]+a[m[1]];
											break;
										case 2:
											x1=a[m[0]]-a[m[1]];
											break;
										case 3 :
											x1=a[m[0]]*a[m[1]];
											break;
										case 4 :
											x1=a[m[0]]/a[m[1]];
											break;
									}
									switch(op3){
										case 1:
											x2=a[m[2]]+a[m[3]];
											break;
										case 2:
											x2=a[m[2]]-a[m[3]];
											break;		
										case 3 :
											x2=a[m[2]]*a[m[3]];
											break;
										case 4 :
											x2=a[m[2]]/a[m[3]];
											break;
									}
									switch(op2){
										case 1:
											sum=x1+x2;
											break;
										case 2:
											sum=x1-x2;
											break;	
										case 3 :
											sum=x1*x2;
											break;
										case 4 :
											if(x2==0){
												err=1;
												break;
											}
											else{
												sum=x1/x2;
												break;
											}			
									}
										if(err==1)continue;
										if(fabs(sum-24)<eps&&f==0){
											printf("(%.0lf",a[m[0]]);
											switch(op1){
												case 1 :
													printf("+");
													break;
												case 2 :
													printf("-");
													break;
												case 3 :
													printf("*");
													break;
												case 4 :
													printf("/");
													break;
											}
											printf("%.0lf)",a[m[1]]);
											switch(op2){
												case 1 :
													printf("+");
													break;
												case 2 :
													printf("-");
													break;
												case 3 :
													printf("*");
													break;
												case 4 :
													printf("/");
													break;
											}
											printf("(%.0lf",a[m[2]]);
											switch(op3){
												case 1 :
													printf("+");
													break;
												case 2 :
													printf("-");
													break;
												case 3 :
													printf("*");
													break;
												case 4 :
													printf("/");
													break;
											}
											printf("%.0lf)\n",a[m[3]]);
											f=1;
											}
									}
								}
							}
							for(op1=1;op1<=4;op1++){  //op2-->op1-->op3  (op1(op2))op3
								for(op2=1;op2<=4;op2++){	
									for(op3=1;op3<=4;op3++){ 
										sum=a[m[0]];
										err=0;
									switch(op2){
										case 1:
											x2=a[m[1]]+a[m[2]];
											break;
										case 2:
											x2=a[m[1]]+a[m[2]];
											break;
										case 3 :
											x2=a[m[1]]*a[m[2]];
											break;
										case 4 :
											if(a[m[2]]==0){
												err=1;
												break;
											}
											else{
												x2=a[m[1]]/a[m[2]];
												break;
											}			
									}
									switch(op1){
										case 1 :
											sum+=x2;
											break;
										case 2 :
											sum-=x2;
											break;
										case 3 :
											sum*=x2;
											break;
										case 4 :
											if(x2==0){
												err=1;
												break;
											}
											else{
												sum/=x2;
												break;
											}			
									}
									switch(op3){
										case 1 :
											sum+=a[m[3]];
											break;
										case 2 :
											sum-=a[m[3]];
											break;
										case 3 :
											sum*=a[m[3]];
											break;
										case 4 :
											if(a[m[3]]==0){
												err=1;
												break;
											}
											else{
												sum/=a[m[3]];
												break;
											}			
									}
										if(err==1)continue;
										if(fabs(sum-24)<eps&&f==0){
											printf("(%.0lf",a[m[0]]);
											switch(op1){
												case 1 :
													printf("+");
													break;
												case 2 :
													printf("-");
													break;
												case 3 :
													printf("*");
													break;
												case 4 :
													printf("/");
													break;
											}
											printf("(%.0lf",a[m[1]]);
											switch(op2){
												case 1 :
													printf("+");
													break;
												case 2 :
													printf("-");
													break;
												case 3 :
													printf("*");
													break;
												case 4 :
													printf("/");
													break;
											}
											printf("%.0lf))",a[m[2]]);
											switch(op3){
												case 1 :
													printf("+");
													break;
												case 2 :
													printf("-");
													break;
												case 3 :
													printf("*");
													break;
												case 4 :
													printf("/");
													break;
											}
											printf("%.0lf\n",a[m[3]]);
											f=1;
											}
									}
								}
							}
							for(op1=1;op1<=4;op1++){  //op2-->op3-->op1  op1((op2)op3)
								for(op2=1;op2<=4;op2++){	
									for(op3=1;op3<=4;op3++){ 
										sum=a[m[0]];
										err=0;
									switch(op2){
										case 1:
											x2=a[m[1]]+a[m[2]];
											break;
										case 2:
											x2=a[m[1]]+a[m[2]];
											break;
										case 3 :
											x2=a[m[1]]*a[m[2]];
											break;
										case 4 :
											if(a[m[2]]==0){
												err=1;
												break;
											}
											else{
												x2=a[m[1]]/a[m[2]];
												break;
											}			
									}
									switch(op3){
										case 1 :
											x2+=a[m[3]];
											break;
										case 2 :
											x2-=a[m[3]];
											break;
										case 3 :
											x2*=a[m[3]];
											break;
										case 4 :
											if(x2==0){
												err=1;
												break;
											}
											else{
						  						x2/=a[m[3]];
												break;
											}			
									}
									switch(op1){
										case 1 :
											sum+=x2;
											break;
										case 2 :
											sum-=x2;
											break;
										case 3 :
											sum*=x2;
											break;
										case 4 :
											if(x2==0){
												err=1;
												break;
											}
											else{
												sum/=x2;
												break;
											}			
									}
										if(err==1)continue;
										if(fabs(sum-24)<eps&&f==0){
											printf("%.0lf",a[m[0]]);
											switch(op1){
												case 1 :
													printf("+");
													break;
												case 2 :
													printf("-");
													break;
												case 3 :
													printf("*");
													break;
												case 4 :
													printf("/");
													break;
											}
											printf("((%.0lf",a[m[1]]);
											switch(op2){
												case 1 :
													printf("+");
													break;
												case 2 :
													printf("-");
													break;
												case 3 :
													printf("*");
													break;
												case 4 :
													printf("/");
													break;
											}
											printf("%.0lf)",a[m[2]]);
											switch(op3){
												case 1 :
													printf("+");
													break;
												case 2 :
													printf("-");
													break;
												case 3 :
													printf("*");
													break;
												case 4 :
													printf("/");
													break;
											}
											printf("%.0lf)\n",a[m[3]]);
											f=1;
											}
									}
								}
							}
							for(op1=1;op1<=4;op1++){  //op3-->op2-->op1  op1(op2(op3))
								for(op2=1;op2<=4;op2++){	
									for(op3=1;op3<=4;op3++){ 
										sum=a[m[0]];
										err=0;
										x2=a[m[1]];
									switch(op3){
										case 1:
											x3=a[m[2]]+a[m[3]];
											break;
										case 2:
											x3=a[m[2]]+a[m[3]];
											break;
										case 3 :
											x3=a[m[2]]*a[m[3]];
											break;
										case 4 :
											if(a[m[3]]==0){
												err=1;
												break;
											}
											else{
												x3=a[m[2]]/a[m[3]];
												break;
											}			
									}
									switch(op2){
										case 1 :
											x2+=x3;
											break;
										case 2 :
											x2-=x3;
											break;
										case 3 :
											x2*=x3;
											break;
										case 4 :
											if(x3==0){
												err=1;
												break;
											}
											else{
						  						x2/=x3;
												break;
											}			
									}
									switch(op1){
										case 1 :
											sum+=x2;
											break;
										case 2 :
											sum-=x2;
											break;
										case 3 :
											sum*=x2;
											break;
										case 4 :
											if(x2==0){
												err=1;
												break;
											}
											else{
												sum/=x2;
												break;
											}			
									}
										if(err==1)continue;
										if(fabs(sum-24)<eps&&f==0){
											printf("%.0lf",a[m[0]]);
											switch(op1){
												case 1 :
													printf("+");
													break;
												case 2 :
													printf("-");
													break;
												case 3 :
													printf("*");
													break;
												case 4 :
													printf("/");
													break;
											}
											printf("(%.0lf",a[m[1]]);
											switch(op2){
												case 1 :
													printf("+");
													break;
												case 2 :
													printf("-");
													break;
												case 3 :
													printf("*");
													break;
												case 4 :
													printf("/");
													break;
											}
											printf("(%.0lf",a[m[2]]);
											switch(op3){
												case 1 :
													printf("+");
													break;
												case 2 :
													printf("-");
													break;
												case 3 :
													printf("*");
													break;
												case 4 :
													printf("/");
													break;
											}
											printf("%.0lf))\n",a[m[3]]);
											f=1;
											}
									}
								}
							}
					}
			}
		}
	}
	if(f==0){
	printf("-1\n");
}
    getchar();
    printf("请按任意键继续......");
    getchar();
	return 0;
}

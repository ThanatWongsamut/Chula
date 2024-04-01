//
// Created by TitorPs360 on 17/8/2022 AD.
//

#include<stdio.h>

int main(){
    int M,N,R,r1,c1,r2,c2,m,i,j;
    scanf("%d%d%d",&N,&M,&R);
    int t[N+1][M+1];
    for(i=1;i<=N;i++)for(j=1;j<=M;j++)scanf("%d",&t[i][j]);
    while(R--){
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        if(r1>r2||c1>c2){printf("INVALID\n");continue;}
        if(c1<0||r1>N||c2<0||c1>M){printf("OUTSIDE\n");continue;}
        m=t[r1][c1];
        for(i=r1;i<=r2&&i<=N;i++)for(j=c1;j<=c2&&j<=M;j++)if(t[i][j]>m)m=t[i][j];
        printf("%d\n",m);
    }
    return 0;
}
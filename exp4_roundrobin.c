#include<stdio.h>
int q[100];
int f=-1;
int r=-1;
void insert(int n)
{
 if(f==-1)
 f=0;
 r=r+1;
 q[r]=n;
}
int delete()
{ int n;
 n=q[f];
 f=f+1;
 return n;
}
void main()
{
 int p,tq,n,i,j,t=0;
 float twt=0,ttat=0;
 printf("\nEnter the no of processes : ");
 scanf("%d",&n);
 int a[n][5],bt[10],exist[10]={0};
 printf("\nEnter Arrival Time & Burst Time");
 for(i=0;i<n;i++)
 {
    printf("\nProcess ID:");
 scanf("%d",&a[i][0]);
 printf("\nA.T of process%d:",a[i][0]);
 scanf("%d",&a[i][1]);
 printf("\nB.T of process%d:",a[i][0]);
 scanf("%d",&a[i][2]); 
 bt[i]=a[i][2];
 }
 printf("Enter the time quantum:");
 scanf("%d",&tq);
 insert(0);
 exist[0]=1;
 while(f<=r)
 {
 p=delete();
 if(a[p][2]>=tq)
 {
 a[p][2]=a[p][2]-tq;
 t=t+tq;
 }
 else
 {
 t+=a[p][2];
 a[p][2]=0;
 }
 for(i=0;i<n;i++)
 {
 if(exist[i]==0 && a[i][j]<=t)
 { 
 insert(i);
 exist[i]=1;
 }
 }
 if(a[p][2]==0)
 {
 a[p][4]=t-a[p][1];
 a[p][3]=a[p][4]-bt[p];
 ttat=ttat+a[p][4];
 twt=twt+a[p][3];
 }
 else
 {
 insert(p);
 }
 }
printf("Process\tA.t\tB.t\tT.A.T\tW.T\n");
for(i=0;i<n;i++)
{
 printf("%d\t%d\t%d\t%d\t%d\n",a[i][0],a[i][1],bt[i],a[i][4],a[i][3]);
}
printf("\nAverage Turnaround time:%f\n",ttat/n);
printf("\nAverage Waiting time:%f\n",twt/n);
}

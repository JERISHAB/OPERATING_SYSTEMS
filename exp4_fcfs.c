#include<stdio.h>
int main()
{
 int i,n;
 float tsum=0,wsum=0;
 printf("Enter the number of processes:");
 scanf("%d",&n);
 int a[n][5];
 printf("Enter the Arrival Time & Burst Time\n");
 for(i=0;i<n;i++)
 {
 printf("A.T of process %d:",i);
 scanf("%d",&a[i][1]);
 printf("B.T of process %d:",i);
 scanf("%d",&a[i][2]);
 }
 a[0][3]=a[0][2]+1;
 for(i=1;i<n;i++)
 { 
 a[i][3]=a[i-1][3]+a[i][2];
 }
 for(i=0;i<n;i++)
 {
 a[i][4]=a[i][3]-a[i][1];
 a[i][5]=a[i][4]-a[i][2];
 }
 printf("Processes\tA.T\tB.T\tC.T\tT.A.T\tW.T\n");
 for(i=0;i<n;i++)
{
 printf("%d\t\t%d\t%d\t%d\t%d\t%d\n",i,a[i][1],a[i][2],a[i][3],a[i][4],a[i][5]);
 tsum=tsum+a[i][4];
 wsum=wsum+a[i][5];
 }
 printf("Average Turnaround Time:%fms\n",tsum/n);
 printf("Average Waiting Time:%fms\n",wsum/n);
}

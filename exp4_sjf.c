#include<stdio.h>
void swap(int *l,int *r)
{
 int t;
 t=*r;
 *r=*l;
 *l=t;
}
int main()
{
 int i,j,n,cmpt;
 float twt=0,ttat=0;
 printf("Enter the no of processes:");
 scanf("%d",&n);
 int a[n][5];
 
 for(i=0;i<n;i++)
 {
 printf("Enter the AT and BT of process:");
 scanf("%d",&a[i][0]);
 printf("A.T of process %d:",a[i][0]);
 scanf("%d",&a[i][1]);
 printf("B.T of process %d:",a[i][0]);
 scanf("%d",&a[i][2]);
 }
 for(i=0;i<n;i++)
 {
 for(j=n-1;j>1;j--)
 {
 if(a[i][1]>a[j][1])
 {
 
 swap(&a[i][1],&a[j][1]);
 swap(&a[i][2],&a[j][2]);
 }
 }
 }
 a[0][3]=a[0][1];
 a[0][4]=a[0][2]-a[0][1];
 cmpt=a[0][4];
 twt=twt+a[0][3];
 ttat=ttat+a[0][4];
 for(i=1;i<n;i++)
 {
 int m=a[i][2];
 for(j=i+1;j<n;j++)
 {
 if(m>a[j][2] && a[j][1]<cmpt)
 {
 m=a[j][2];
 swap(&a[i][1],&a[j][1]);
 swap(&a[i][2],&a[j][2]);
 }
 }
 a[i][3]=cmpt-a[i][1];
 twt=twt+a[i][3];
 cmpt=cmpt+a[i][2];
 a[i][4]=cmpt-a[i][1];
 ttat=ttat+a[i][4];
 }
 printf("process\tA.T\tB.t\tT.A.T\tW.T\n");
 for(i=0;i<n;i++)
 {
 printf("%d\t%d\t%d\t%d\t%d\n",a[i][0],a[i][1],a[i][2],a[i][4],a[i][3]);
 }
 printf("Average Turnaround time:%f",ttat/n);
 printf("\nAverage Waiting time:%f",twt/n);
}

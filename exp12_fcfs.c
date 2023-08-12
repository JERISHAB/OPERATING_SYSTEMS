#include <stdio.h>
int main() {
int ioq[20], i, n, ihead, tot;
float seek = 0, avgs;
printf("Enter the number of requests: ");
scanf("%d", &n);
printf("Enter the initial head position: ");
scanf("%d", &ihead);
ioq[0] = ihead;
ioq[n + 1] = 0;
printf("Enter the I/O queue requests:");
for (i = 1; i <= n; i++)
scanf("%d", &ioq[i]);
ioq[n + 1] = ioq[n];
printf("Order of requests served:");
for (i = 0; i <= n; i++) {
tot = ioq[i + 1] - ioq[i];
if (tot < 0)
tot = tot * -1;
seek += tot;
printf("%d --> ", ioq[i]);
}
avgs = seek / n;
printf("\nTotal Seek time:\t%.2f\n", seek);
printf("Average seek time:\t%.2f\n", avgs);
return 0;
}

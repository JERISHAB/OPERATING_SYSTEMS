#include <stdio.h>
#define MAX_PROC 10
#define MAX_RES 10
int main() {
 int p, r, i,j;
 printf("Enter the number of processes: ");
 scanf("%d", &p);
 printf("Enter the number of resources: ");
 scanf("%d", &r);
 int allocation[MAX_PROC][MAX_RES],request[MAX_PROC]
[MAX_RES], available[MAX_RES],need[MAX_PROC][MAX_RES], 
finish[MAX_PROC] = {0}; // Initialize finish array to 0
 // Input the allocation matrix
 printf("Enter the allocation matrix:\n");
 for (i = 0; i < p; i++)
 for (j = 0; j < r; j++)
 scanf("%d", &allocation[i][j]);
 printf("Enter the request matrix:\n");
 for (i = 0; i < p; i++)
 for (j = 0; j < r; j++)
 scanf("%d", &request[i][j]);
 printf("Enter the available resources:\n");
 for (i = 0; i < r; i++)
 scanf("%d", &available[i]);
 // Calculate the need matrix
 for (i = 0; i < p; i++)
 for (j = 0; j < r; j++)
 need[i][j] = request [i][j] - allocation[i][j];
 // Detect deadlock
 int c = 0;
 while (c < p) {
 int f = 0;//f-found
 for (i = 0; i < p; i++) {
 if (!finish[i]) {
 int resourcesAvailable = 1;
 for (j = 0; j < r; j++) {
 if (need[i][j] > available[j]) {
 resourcesAvailable = 0;
break;
}
}
if (resourcesAvailable) {
 finish[i] = 1;
 c++;
 f= 1;
 for (j = 0; j < r; j++)
 available[j] += allocation[i][j];
 break;
 }
 }
 }
 if (!f)
 break;
 }
 // Check if deadlock occurred
 if (c < p) {
 printf("Deadlock Detected!\n");
 } else {
 printf("No Deadlock Detected.\n");
}
}
#include <stdio.h>
#include <stdlib.h>


int main()
{
   int n,burst_time[25],waiting_time[25],tat[25];
   float avg_waiting_time,avg_tat;
   int sum_wait=0, sum_tat=0;
   printf("Enter the no. of processes \n");
   scanf("%d",&n);
   printf("Enter the bursts times \n");
   for(int i=1;i<=n;i++)
   {
       printf("Enter the burst time of process %d  ",i);
       scanf("%d",&burst_time[i]);
   }
    waiting_time[1]=0;
    for(int i=2;i<=n;i++)
   {

      waiting_time[i] = burst_time[i-1] + waiting_time[i-1];
   }

    for(int i=1;i<=n;i++)
   {
       printf("The waiting time of process %d is %d \n",i,waiting_time[i]);


   }
   for(int i=1;i<=n;i++)
   {
       sum_wait=sum_wait+waiting_time[i];
   }
   printf("%d \n",sum_wait);
   avg_waiting_time= (sum_wait / n);

   for(int i=1;i<=n;i++)
   {

      tat[i] = burst_time[i] + waiting_time[i];
   }
    for(int i=1;i<=n;i++)
   {
       printf("The turn around time of process %d is %d \n",i,tat[i]);
   }
    for(int i=1;i<=n;i++)
   {
       sum_tat=sum_tat+tat[i];
   }
 printf("%d \n",sum_tat);
   avg_tat= sum_tat/n;

    printf("The average waiting time  is %f : \n",avg_waiting_time);
   printf("The average turn around time is %f : \n",avg_tat);

   return(0);
}


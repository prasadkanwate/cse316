#include<stdio.h>
int main()
{
    int AT[20],BT[20],P[20],WT[20],TAT[20],PR[20],RT[20];
    int k,l,n,pos,Temp;
    int Total=0;
    int ct,TQ,remain=n,Time,Flag=0;
    float Avg_wt=0,Avg_tat=0;
 
    printf("\nEnter No of Processes?:");
    scanf("%d",&n);
      for(k=0;k<n;k++)
    {
        printf("\nP[%d]\n",k+1);
        printf("Enter priority :");
        scanf("%d",&PR[k]);
        printf("Enter Arrival Time :");
        scanf("%d",&AT[k]);
        printf("Enter Burst Time :");
        scanf("%d",&BT[k]);
     P[k]=k+1;           
    }   
    for(k=0;k<n;k++)
    {
        pos=k;
        for(l=l+1;l<n;l++)
        {
            if(PR[l]<PR[pos])
                pos=l;
        }
        Temp=PR[k];
        PR[k]=PR[pos];
        PR[pos]=Temp;
        Temp=BT[k];
        BT[k]=BT[pos];
        BT[pos]=Temp;
        Temp=P[k];
        P[k]=P[pos];
        P[pos]=Temp;
    }
    printf("\nPlease Enter Time Quantum : ");
    scanf("%d",&TQ);	
   for(Time=0;ct=0;remain!=0) 
    { 
     if(RT[ct]<=TQ && RT[ct]>0) 
      { 
        Time+=RT[ct]; 
        RT[ct]=0; 
        Flag=1;
      } 
      else if(RT[ct]>0) 
      { 
        RT[ct]-=TQ; 
        Time+=TQ; 
      } 
    }
    
    WT[0]=0;
    for(k=1;k<n;k++)
    {
        WT[k]=0;
        for(l=0;l<k;l++)
            WT[k]+=BT[l];
       Total+=WT[l];
    }
    Avg_wt=(float)Total/n;     
    Total=0;
  
    printf("\nP_ID\tPriority\tArrival Time\tBurst Time \tWaiting Time\tTurnaround Time");
    for(k=0;k<n;k++)
     {
        TAT[k]=BT[k]+WT[k];     
        WT[k]=TAT[k]-BT[k];
       Avg_tat+=Total;

        printf("\nP[%d]  \t   %d\t \t      %d\t\t    %d\t \t     %d\t  \t  \t%d\t",P[k],PR[k],AT[k],BT[k],WT[k],TAT[k]);
     }
    
    //Avg_wt=i;
     
    Avg_tat=(float)Total/n;
    printf("\n\nAVERAGE WAITING TIME= %f\n",Avg_wt);
    printf("\nAVERAGE TURNAROUND TIME= %f",Avg_tat);
 
    return 0;
}


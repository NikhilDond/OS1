#include<stdio.h>
#include<stdlib.h>
int allocation[50][50],max[20][20],available[20],need[20][20],safe[10],s=0;
int finish[20],work[10],cnt=0,flag=0,temp=0,p,r,i,j,ch,index,req[10];

void check()
{
    temp=0;
    s=0;
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
        
    }

    printf("Allocation table is\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("%d\t",allocation[i][j]);
        }
        printf("\n");
    }

    printf("Need table is=\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < p; i++)
    {
        finish[i]=0;
    }
    for (i = 0; i < r; i++)
    {
        work[i]=available[i];
    }

    while(temp<2)
    {
        for (i = 0; i < p; i++)
        {
            for ( j = 0; j < r; j++)
            {
                if (finish[i]==0 && need[i][j]<=work[j])
                {
                    flag=1;
                }
                else
                {
                    flag=0;break;
                }              
            }
            if (flag==1)
            {
                for ( j = 0; j < r; j++)
                {
                    work[j]=work[j]+allocation[i][j];
                }
                finish[i]=1;
                safe[s++]=i;
                
            }
        }
        temp++;
        
    }
    flag=0;
    for ( i = 0; i < p; i++)
    {
        if (finish[i]==0)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        printf("\nSystem is in deadlock state");
    }
    else
    {
        printf("\nSystem is in safe state");
        printf("\nSafe sequence is\n");
        for (size_t i = 0; i < p; i++)
        {
            printf("P%d\t",safe[i]);
        }
    }
}

void main()
{
    printf("Enter the no of resources and processes=\n");
    scanf("%d%d",&r,&p);
    printf("\nEnter the allocation table=\n");
    for (i = 0; i < p; i++)
    {
        for ( j = 0; j < r; j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }
    printf("\nEnter the max table=\n");
    for ( i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    printf("\nEnter the vector available=\n");
    for ( i = 0; i < r; i++)
    {
        scanf("%d",&available[i]);
    }
    check();
    
    printf("\nDo you want to add new request=\n");
    printf("Enter 1 for yes and 0 for no\n");
    scanf("%d",&ch);
    if (ch==0)
    {
        exit(1);
    }
    printf("Enter the process no=\n");
    scanf("%d",&index);
    printf("\nEnter the request=\n");
    for (size_t i = 0; i < r; i++)
    {
        scanf("%d",&req[i]);
    }
    flag=0;
    for (size_t i = 0; i < r; i++)
    {
        if (req[i]<=need[index][i])
        {
            flag=1;
        }
        else
        {
            flag=0;
        }
    }
    if(flag==0)
    {
        printf("\nRequest cannot be satisfied");
    }

    for (size_t i = 0; i < r; i++)
    {
        if (req[i]<=available[i])
        {
            flag=1;
        }
        else
        {
            flag=0;
        }
    }
    if(flag==0)
    {
        printf("\nRequest cannot be satisfied");
        exit(1);
    }

    for (i = 0; i < r; i++)
    {
        allocation[index][i]=allocation[index][i]+req[i];
        available[i]=available[i]-req[i];
    }
    check();
    return 0;
}

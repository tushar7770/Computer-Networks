
//CS20B1098 TUSHAR PANJETA
//CODE FOR DVR
#include<stdio.h>
#include<limits.h>
#define size 15

struct edge
{
	unsigned dist[size];
	unsigned from[size];
}rt[size];

int main()
{
    int n;
    printf("\nEnter the total no of routers : ");
    scanf("%d",&n);
	int cost[n][n];
	int count=0;
    printf("\nInstruction for inputing the cost\n1. Enter zero if the source and destination is same or their is no edge between  them\n2. If source and distance are different and has edge/path between them then input that cost\n");

	for(int i=0;i<n;i++)
    {
        printf("\nEnter the cost of routers with respect to %c router : ",i+65);
        for(int j=0;j<n;j++)
		{	
			scanf("%d",&cost[i][j]);
            if (cost[i][j]==0)
            {
                cost[i][j]=INT_MAX;
            }
            
			cost[i][i]=0;
			rt[i].dist[j]=cost[i][j];//intiallizing the cost
			rt[i].from[j]=j;//putting path as directly using the destination node
		}
    }
    printf("\n   ------Intiall Routing tables------\n");
    for(int i=0;i<n;i++)
    {
        printf("\n      ======Router %c table======\n",65+i);
        printf("Destination\tDistance\tNext Hop\n");
        for(int j=0;j<n;j++)
        {
            if(rt[i].dist[j]== INT_MAX)
            {
                printf("%c\t\tinfinity\t\t--\n",j+65);
            }
            else
            {
                printf("%c\t\t%d\t\t%c\n",j+65,rt[i].dist[j],rt[i].from[j]+65);
            }
        }
        printf("\n    * - - - - - ___________ - - - - - *\n");
    }	

    printf("\n\n   ------Intermediate Routing tables------\n");
    do
    {
        count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(rt[i].dist[j]>cost[i][k]+rt[k].dist[j])//checking if cheaper cost method is avilable for the the tranfer of data by changing the route
                    {
                        rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];//updating the new cost
                        rt[i].from[j]=k;//updating the next hop
                        count++;
                    }

                }
				
            }
            printf("\n      ======Router %c table======\n",65+i);
            printf("Destination\tDistance\tNext Hop\n");
            for(int j=0;j<n;j++)
            {
                if(rt[i].dist[j]== INT_MAX)
                {
                    printf("%c\t\tinfinity\t\t--\n",j+65);
                }
                else
                {
                    printf("%c\t\t%d\t\t%c\n",j+65,rt[i].dist[j],rt[i].from[j]+65);
                }
            }
            printf("\n    * - - - - - ___________ - - - - - *\n");	
			
        }
			
        
    }while(count!=0);
	printf("\n*******************************************************************\n");	
	printf("\n   ------FINAL Routing tables------\n");
    for(int i=0;i<n;i++)
    {
        printf("\n      ======Router %c table======\n",65+i);
        printf("Destination\tDistance\tNext Hop\n");
        for(int j=0;j<n;j++)
        {
            printf("%c\t\t%d\t\t%c\n",j+65,rt[i].dist[j],rt[i].from[j]+65);
        }
        printf("\n    * - - - - - ___________ - - - - - *\n");
    }	
    printf("\n*******************************************************************\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int nr,nf,ref[100],frame[50],flag,pgfc=0,victim=-1,i,j;

void getData()
{
     printf("Enetr the length of the reference string \n");
    scanf("%d",&nr);
    printf("Enetr the reference strng \n");
    for(i=0;i<nr;i++)
    {
        scanf("%d",&ref[i]);

    }
    printf("Enetr the no. of frames \n");
    scanf("%d",&nf);
}

void initialize()
{
    for(i=0;i<nf;i++)
    {
        frame[i]=-1;
    }
}

void fifo()
{initialize();
    for(i=0;i<nr;i++)
    {
        flag=0;
        printf("\n %d--> ",ref[i]);
        for(j=0;j<nf;j++)
        {
            if(frame[j]==ref[i])
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            pgfc++;
            victim++;
            victim=victim%nf;
            frame[victim]=ref[i];
            for(j=0;j<nf;j++)
            {
                printf("%d \n",frame[j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("The page fault count is %d",pgfc);
}
int main()
{int ch;

while(1)
{
    printf("1.GETDATA 2.fifo 3.EXIT \n");
    printf("Enetr your choice \n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:getData();
               break;
         case 2:fifo();
                break;
        case 3: return 0;
    }

}
}



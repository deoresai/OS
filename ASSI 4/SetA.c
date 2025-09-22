#include <stdio.h>
#define size 16
void FIFO(int n, int str[])
{
    int frame[n], i, j;
    for (i = 0; i < n; i++)
    {
        frame[i] = -1;
    }
    int found, PF = 0, top = 0;
    for (i = 0; i < size; i++)
    {
        found = 0;
        for (j = 0; j < n; j++)
        {
            if (str[i] == frame[j])
            {
                found = 1;
            }
        }
        if (!found)
        {
            frame[top] = str[i];
            PF++;
            top = (top + 1) % n;
        }
    }
    printf("page Fault is: %d\n", PF);
}
void LRU(int str[], int n)
{
    int frame[n], last_use[n],i;
    for (i = 0; i < n; i++)
    {
        frame[i] = -1;
        last_use[i] = -1;
    }
    int  k, j,PF=0,min=999;
    for (int i = 0; i < size; i++)
    {
        int found = 0;
        for (j = 0; j < n; j++)
        {
            if (frame[j] == str[i])
            {
                found = 1;
                last_use[j] = i;
                break;
            }
        }
        if (!found)
        {
            PF++;
            int index = 0;
            for (k = 0; k < n; k++)
            {
                if (frame[k]==-1)
                {
                    index=k;
                    break;
                }
                if (last_use[k]<last_use[index])
                {
                    index=k;
                }
                
            }
            frame[index]=str[i];
            last_use[index]=i;
        }
    }
    printf("page fault (LRU): %d ",PF);
}
int main()
{
    int str[16] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
    int n;
    printf("How many number of frames: ");
    scanf("%d", &n);
    FIFO(n, str);
    LRU(str, n);
    return 0;
}

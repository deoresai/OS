#include <stdio.h>
struct process
{
    int pid;
    int arrT;
    int busT;
    int WT;
    int TAT;
    int CT;
    int remT;
};
int main()
{
    int n, i;
    printf("How many process are there\n");
    scanf("%d", &n);
    struct process p[n];
    for (i = 0; i < n; i++)
    {
        p[i].pid = i+1;
        printf("\nEnter a arrivel time P %d: \t",i+1);
        scanf("%d",&p[i].arrT);
        printf("\nEnter a burst time P %d: \t",i+1);
        scanf("%d",&p[i].busT);
        p[i].remT = p[i].busT;
    }
    int completed = 0, done[n], time = 0;
    for (i = 0; i < n; i++)
    {
        done[i] = 0;
    }
    int totalTAT=0,totalWT=0;
    while (completed < n)
    {
        int i = -1, min = 999, j;
        for (j = 0; j < n; j++)
        {
            if (p[j].arrT <= time && !done[j] && p[j].remT < min)
            {
                min = p[j].remT;
                i = j;
            }
        }
        if (i != -1)
        {
            p[i].remT--;
            time++;
            if (p[i].remT == 0)
            {
                completed++;
                done[i]=1;
                p[i].CT = time;
                p[i].TAT = p[i].CT - p[i].arrT;
                p[i].WT = p[i].TAT - p[i].busT;

                totalTAT += p[i].TAT;
                totalWT += p[i].WT;
            }
        }
        else{
            time++;
        }
    }
       printf("\npid\tarrT\tbusT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrT, p[i].busT, p[i].CT, p[i].TAT, p[i].WT);
    }
    printf("\nAvrage TAT = %.2f\t",(float)totalTAT/n);
    printf("\nAvrage WT = %.2f\t",(float)totalWT/n);

    return 0;
}
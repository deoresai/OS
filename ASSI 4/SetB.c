#include <stdio.h>
#define SIZE 16
void OPT(int ref[], int n)
{
    int frame[n], PF = 0;
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        frame[i] = -1;
    }
    for (i = 0; i < SIZE; i++)
    {
        int found = 0;
        for (j = 0; j < n; j++)
        {
            if (frame[j] == ref[i])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            int index = -1;
            PF++;
            for (j = 0; j < n; j++)
            {
                if (frame[j] == -1)
                {
                    index = j;
                    break;
                }
            }
            if (index == -1)
            {
                int usemx = -1;
                for (j = 0; j < n; j++)
                {
                    int next = -1;
                    for (k = i + 1; k < SIZE; k++)
                    {
                        if (frame[j] == ref[k])
                        {
                            next = k;
                            break;
                        }
                    }
                    if (next == -1)
                    {
                        index = j;
                        break;
                    }
                    if (next > usemx)
                    {
                        usemx = next;
                        index = j;
                    }
                }
            }
            frame[index] = ref[i];
        }
    }
    printf("page fault by (OPT): %d ", PF);
}
void MFU(int ref[], int n)
{
    int frame[n], freq[SIZE] = {0};
    int i, j;

    for (i = 0; i < n; i++)
        frame[i] = -1;

    int PF = 0;

    for (i = 0; i < SIZE; i++)
    {
        int found = 0;

        for (j = 0; j < n; j++)
        {
            if (frame[j] == ref[i])
            {
                found = 1;
                break;
            }
        }

        freq[ref[i]]++;
        if (!found)
        {
            PF++;

            int placed = 0;

            for (j = 0; j < n; j++)
            {
                if (frame[j] == -1)
                {
                    frame[j] = ref[i];
                    placed = 1;
                    break;
                }
            }

            if (!placed)
            {

                int maxFreq = -1, replaceIndex = 0;
                for (j = 0; j < n; j++)
                {
                    if (freq[frame[j]] > maxFreq)
                    {
                        maxFreq = freq[frame[j]];
                        replaceIndex = j;
                    }
                }
                frame[replaceIndex] = ref[i];
            }
        }
    }

    printf("Total Page Faults by (MFU): %d\n", PF);
}

int main()
{
    int ref[SIZE] = {12, 15, 12, 18, 6, 8, 11, 12,
                     19, 12, 6, 8, 12, 15, 19, 8};
    int n;
    printf("Enter number of frames: ");
    scanf("%d", &n);

    OPT(ref, n);
    MFU(ref, n);
    return 0;
}

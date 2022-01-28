#include <stdio.h>
#include <string.h>

char str1[1001]={0};
char str2[1001]={0};
int count[1000]={0};
int len1, len2;

int main(void)
{
    int i, j, k;
    int max;
    scanf("%s %s", &str1, &str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    for(i=0;i<len1;i++)
    {
        for(j=len2-1;j>=0;j--)
        {
            if(str1[i]==str2[j])
            {
                max=0;
                for(k=0;k<j;k++)
                {
                    if(count[k]>max)
                    {
                        max = count[k];
                    }
                }
                count[j] = max + 1;

                // count[j]++;
                // for(k=j+1;k<len2;k++)
                // {
                //     if(count[k]<count[j])
                //     {
                //         count[k] = count[j];
                //     }
                // }
                // This doesn't work. 
            }
        }
    }
    max=0;
    for(i=0;i<len2;i++)
    {
        if(count[i]>max)
        {
            max = count[i];
        }
    }
    printf("%d", max);
    // printf("%d", count[len2-1]);
    return 0;
}
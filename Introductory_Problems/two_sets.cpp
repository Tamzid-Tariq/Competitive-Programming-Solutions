/*
Problem: Two Sets
Link: https://cses.fi/problemset/task/1092/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

void functionR48Q10()
{

    long long int a = 0;

    scanf("%lld", &a);

    // long long int ans[a],wer[a];

    long long int *ans = (long long int *)malloc(a * sizeof(long long int));

    long long int *wer = (long long int *)malloc(a * sizeof(long long int));

    long long int count = 0;
    long long int count1 = 0;

    long long int sum = a * (a + 1) / 2;

    long long int equalportion = sum / 2;

    if ((sum % 2) == 0)
    {

        printf("YES\n");

        for (long long int i = a; i >= 1; i--)
        {

            if (equalportion >= i)
            {

                ans[count] = i;

                count++;

                equalportion -= i;
            }

            else
            {
                wer[count1] = i;

                count1++;
            }
        }

        printf("%lld\n", count);

        for (long long int i = 0; i < count; i++)
        {

            printf("%lld ", ans[i]);
        }
        printf("\n");

        printf("%lld\n", count1);

        for (long long int i = 0; i < count1; i++)
        {

            printf("%lld ", wer[i]);
        }
        printf("\n");
    }

    else
        printf("NO\n");
}

int main()
{

    functionR48Q10();

    return 0;
}
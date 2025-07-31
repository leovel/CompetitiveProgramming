#define _CRT_SECURE_NO_WARNINGS

#include "bits/stdc++.h";
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n), n)
    {
        // Initialize profit array - each minute costs $0.08
        double profit[1440];
        for (int i = 0; i < 1440; i++)
        {
            profit[i] = -0.08;
        }
        
        // Add sales profits to corresponding minutes
        for (int i = 0; i < n; i++)
        {
            int timestamp;
            double sale_profit;
            scanf("%d %lf", &timestamp, &sale_profit);
            profit[timestamp] += sale_profit;
        }
        
        // Find maximum subarray using Kadane's algorithm variation
        double max_profit = 0;
        double current_sum = 0;
        int best_start = 0, best_length = 0;
        int current_start = 0;
        
        for (int i = 0; i < 1440; i++)
        {
            current_sum += profit[i];
            
            // Update best solution if we found a better one
            if (current_sum > max_profit || 
                (current_sum == max_profit && i - current_start + 1 < best_length))
            {
                max_profit = current_sum;
                best_start = current_start;
                best_length = i - current_start + 1;
            }
            
            // Reset if current sum becomes negative (better to start fresh)
            if (current_sum < 10e-9)
            {
                current_sum = 0;
                current_start = i + 1;
            }
        }
        
        if (max_profit <= 0)
        {
            printf("no profit\n");
        }
        else
        {
            printf("%.2f %d %d\n", max_profit, best_start, best_start + best_length - 1);
        }
    }
    
    return 0;
}

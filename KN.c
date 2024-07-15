
#include <stdio.h>
// Function to return the maximum of two integers
int max(int a, int b) {
return (a > b) ? a : b;
}
// Function to solve the 0/1 Knapsack problem using Dynamic Programming
int knapsack(int W, int weight[], int value[], int n) {
int i, w;
int dp[n+1][W+1];
// Build the dp table in bottom-up manner
for (i = 0; i <= n; i++) {
for (w = 0; w <= W; w++) {
if (i == 0 || w == 0)
dp[i][w] = 0;
else if (weight[i-1] <= w)
dp[i][w] = max(value[i-1] + dp[i-1][w - weight[i-1]], dp[i1][w]);
else
dp[i][w] = dp[i-1][w];
}
}
// The maximum value that can be obtained with the given capacity
return dp[n][W];
}
int main() {
int n, W;
printf("Enter the number of items: ");
scanf("%d", &n);
int value[n], weight[n];
printf("Enter the values of the items:\n");
for (int i = 0; i < n; i++) {
scanf("%d", &value[i]);
}
printf("Enter the weights of the items:\n");
for (int i = 0; i < n; i++) {
scanf("%d", &weight[i]);
}
printf("Enter the capacity of the knapsack: ");
scanf("%d", &W);
printf("Maximum value in Knapsack = %d\n", knapsack(W, weight, value, n));
return 0;
}

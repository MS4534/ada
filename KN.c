
#include <stdio.h>

int max(int a, int b) {
return (a > b) ? a : b;
}

int knapsack(int W, int weight[], int value[], int n) {
int i, w;
int dp[n+1][W+1];

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

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 1000000
#define MAX_VERTICES 10

int N;
int W[MAX_VERTICES][MAX_VERTICES];

int dp[MAX_VERTICES][MAX_VERTICES];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int BacktrackTSP(int current, int visited) {
    int result;
    int bestsolution = dp[current][visited];
    if(bestsolution != 0) {
        return bestsolution;
    }

    if(visited == ((1<<N)-1)){
        if(W[current][0] != 0){
            return W[current][0];
        }
        return INF;
    }

    bestsolution = INF;
    for (int i = 0; i < N; i++){
    if(W[current][i] == 0 || (visited & (1<< i))){
        continue;
    }
    bestsolution = min(bestsolution, W[current][i] + BacktrackTSP(i, visited | 1 << i));
    }

    dp[current][visited] = bestsolution;

    return bestsolution;
}

int main() {
    int i, j;

    printf("Enter the number of nodes : ");
    scanf("%d", &N);

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            scanf("%d", &W[i][j]);
        }
    }

    int result = BacktrackTSP(0, 1);
    printf("\n The total distance of TSP = %d \n", result);
    return 0;
}
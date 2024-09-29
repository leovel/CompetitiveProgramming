#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
using namespace std;

int N, A, B, maxSum, setA[101] = {0}, setB[101] = {0}, tempA[101], tempB[101];

//static void countSort(int n)
//{
//	int i, countA[101], countB[101], *outputA = new int[n](), *outputB = new int[n]();
//
//	memcpy(&countA, &setA, sizeof(int) * 101);
//	memcpy(&countB, &setB, sizeof(int) * 101);
//
//	for (i = 1; i < 101; i++)
//	{
//		countA[i] += countA[i - 1];
//		countB[i] += countB[i - 1];
//	}
//        
//
//    for (i = n - 1; i >= 0; i--) {
//        outputA[countA[A[i]]-- - 1] = A[i];
//		outputB[countB[B[i]]-- - 1] = B[i];
//    }
//
//	memcpy(&A, outputA, sizeof(int) * n);
//	memcpy(&B, outputB, sizeof(int) * n);
//}



//static void countSort(int n)
//{
//	int i, countA[101], countB[101], *outputA = new int[n](), *outputB = new int[n]();
//
//	memcpy(&countA, &setA, sizeof(int) * 101);
//	memcpy(&countB, &setB, sizeof(int) * 101);
//
//	for (i = 1; i < 101; i++)
//	{
//		countA[i] += countA[i - 1];
//		countB[i] += countB[i - 1];
//	}
//        
//
//    for (i = n - 1; i >= 0; i--) {
//        outputA[countA[A[i]]-- - 1] = A[i];
//		outputB[countB[B[i]]-- - 1] = B[i];
//    }
//
//	memcpy(&A, outputA, sizeof(int) * n);
//	memcpy(&B, outputB, sizeof(int) * n);
//}



int main()
{
    scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &A, &B);
		setA[A]++; setB[B]++;

		int posA = 1, posB = 100;

		maxSum = 0;
		memcpy(&tempA, &setA, sizeof(int) * 101);
		memcpy(&tempB, &setB, sizeof(int) * 101);
		while (posA < 101 && posB > 0)
		{
			while (posA < 101 && tempA[posA] == 0)
				posA++;

			while (posB > 0 && tempB[posB] == 0)
				posB--;

			if (posA < 101 && posB > 0)
			{
				maxSum = max(maxSum, posA + posB);

				int minAB = min(tempA[posA], tempB[posB]);
				tempA[posA] -= minAB;
				tempB[posB] -= minAB;
			}
		}
		printf("%d\n", maxSum);
	}
}

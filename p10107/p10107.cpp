#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int X, N, mL;
vi listX;

int main()
{
   N = 0;
   listX = vi();

   while (scanf("%d", &X) != EOF)
   {
	   N++;
	   listX.push_back(X);
	   if (N % 2 == 0)
	   {
		   nth_element(listX.begin(), listX.begin() + (N / 2 - 1), listX.end());
		   mL = listX[N / 2 - 1];
		   nth_element(listX.begin(), listX.begin() + N / 2, listX.end());

		   printf("%d\n", (mL + listX[N / 2]) / 2);
	   }
	   else
	   {
		   nth_element(listX.begin(), listX.begin() + N / 2, listX.end());
		   printf("%d\n", listX[N / 2]);
	   }
   }
}


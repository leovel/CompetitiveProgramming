#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

//static long long getMax(int n)
//{
//    long long mx = arr[0];
//    for (int i = 1; i < n; i++)
//        if (arr[i] > mx)
//            mx = arr[i];
//    return mx;
//}
//
//static void countSort(int n, int exp)
//{
//    int i, count[BASE] = { 0 };
//
//    for (i = 0; i < n; i++)
//        count[(arr[i] / exp) % BASE]++;
//
//    for (i = 1; i < BASE; i++)
//        count[i] += count[i - 1];
//
//    for (i = n - 1; i >= 0; i--) {
//        output[count[(arr[i] / exp) % BASE] - 1] = arr[i];
//        count[(arr[i] / exp) % BASE]--;
//    }
//
//    for (i = 0; i < n; i++)
//        arr[i] = output[i];
//}
//
//static void radixsort(int n)
//{
//    long long m = getMax(n);
//
//    for (long long exp = 1; m / exp > 0; exp *= BASE)
//        countSort(n, exp);
//}

static bool arrayIsSorted(int* a, int n) {
    for (int i = 0; i < n - 1; ++i) if (a[i] > a[i + 1]) return false;
    return true;
}

// by Kenneth Chiguichon
static void radixSort(int* a, int n) {
    const int INT_BIT_SIZE = sizeof(int) << 3, RADIX = 0x100, MASK = RADIX - 1, MASK_BIT_LENGTH = 8;
    int* result = new int[n](), * buckets = new int[RADIX](), * startIndex = new int[RADIX](), * temp = nullptr;
    int flag = 0, key = 0;
    bool hasNeg = false;
    while (flag < INT_BIT_SIZE) {
        for (int i = 0; i < n; ++i) {
            key = (a[i] & (MASK << flag)) >> flag;
            if (key < 0) {
                key += MASK;
                hasNeg = true;
            }
            ++buckets[key];
        }
        startIndex[0] = 0;
        for (int j = 1; j < RADIX; ++j) startIndex[j] = startIndex[j - 1] + buckets[j - 1];
        for (int i = n - 1; i >= 0; --i) {
            key = (a[i] & (MASK << flag)) >> flag;
            if (key < 0) key += MASK;
            result[startIndex[key] + --buckets[key]] = a[i];
        }
        memcpy(a, result, n * sizeof(int));
        flag += MASK_BIT_LENGTH;
    }
    if (hasNeg) {
        int indexOfNeg = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                indexOfNeg = i;
                break;
            }
        }
        memcpy(a, result + indexOfNeg, (n - indexOfNeg) * sizeof(int));
        memcpy(a + (n - indexOfNeg), result, indexOfNeg * sizeof(int));
    }
    delete[] result;
    delete[] buckets;
    delete[] startIndex;
}

long long A, B, C, X, Y, V;
int TC, N, arr[1000001];


int main()
{
    scanf("%d", &TC);
    while (TC--)
    {
        scanf("%d", &N);
        scanf("%lld %lld %lld", &A, &B, &C);
        scanf("%lld %lld", &X, &Y);

        arr[0] = A;
        for (int i = 1; i < N; i++)
        {
            arr[i] = (int)(((long long)arr[i - 1] * B + A) % C);
        }

        if(!arrayIsSorted(arr, N))
            radixSort(arr, N);

        V = 0;
        for (int i = 0; i < N; i++)
        {
            V = (V * X + arr[i]) % Y;
        }

        printf("%lld\n", V);
    }
}

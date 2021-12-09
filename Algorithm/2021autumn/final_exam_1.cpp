#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//함수 선언
int findPivot(int l, int r);
int inPlacePartition(int **L, int l, int r, int k);
void inPlaceQuickSort(int **L, int l, int r);
int same;
int a, b;
int main()
{
    int *A;
    int n, data;

    scanf("%d", &n);
    A = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        A[i] = data; //입력
    }

    inPlaceQuickSort(&A, 0, n - 1); //정렬
    for (int i = 0; i < n; i++)
    {
        printf(" %d", A[i]); //출력
    }
    return 0;
}
//무작위 pivot 선택
int findPivot(int l, int r)
{
    srand(time(NULL));               //시드 설정
    return rand() % (r - l + 1) + l; // l부터 r사이 값
}

int inPlacePartition(int **L, int l, int r, int k)
{
    int *A = (*L);
    int p = A[k]; //피봇값
    int tmp;

    tmp = A[k];
    A[k] = A[r];
    A[r] = tmp;

    int i = l;
    int j = r - 1;
    same = 0;
    while (i <= j)
    {
        while (i <= j && A[i] <= p) //크로스안되고
        {
            if (A[i] == p)
            {
                same++;
            }
            i++; //피봇값보다 작거나 같은 애들이면 오른쪽 한 칸
        }
        while (j >= i && A[j] >= p) //크로스안되고 피봇보다 크거나 같으면 왼쪽으로 한 칸
        {
            if (A[j] == p)
            {
                same++;
            }
            j--;
        }
        if (i < j) //중간에 걸리는 값이 있다는 것이므로 둘이 바꾸기
        {
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    tmp = A[i];
    A[i] = A[r];
    A[r] = tmp;
    tmp = A[i];
    int x = i;
    while (A[x] == tmp)
    {
        x--;
    }
    a = x;
    b = x + same;
    return i; // 피봇 위치 리턴
}

void inPlaceQuickSort(int **L, int l, int r) //퀵
{
    if (l < r)
    {
        int k = findPivot(l, r);              //피봇
        int i = inPlacePartition(L, l, r, k); //파티션
        inPlaceQuickSort(L, l, a - 1);        //피봇보다 작은 값들 끼리 퀵정렬
        inPlaceQuickSort(L, b + 1, r);        //피봇보다 큰 값들 끼리 퀵정렬
    }
}
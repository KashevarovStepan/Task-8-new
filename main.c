#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void swap(int*a,int*b)
{
    int c=*a;
    *a=*b;
    *b=c;
}

void bubbleSort(int*p,int n,int*c,int*in)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(p[j]>p[j+1])
            {
                swap(&p[j],&p[j+1]);
                *in=*in+1;
            }
            *c=*c+1;
        }
    }
}

void quickSort(int*p,int n,int*c,int*in,int l,int r)
{
    if(l>=r)return;
    int mid=l+(r-l)/2;
    int i=l,j=r;
    while(i<=j)
    {
        while(i<mid&&p[i]<p[mid])
        {
            *c=*c+1;
            i++;
        }
        if(i!=mid)*c=*c+1;
        while(j>mid&&p[j]>p[mid])
        {
            *c=*c+1;
            j--;
        }
        if(j!=mid)*c=*c+1;
        if(i<=j)
        {
            if(i!=j)
            {
                swap(&p[i],&p[j]);
                *in=*in+1;
            }
            i++;
            j--;
        }
    }
    quickSort(p,n,c,in,l,j);
    quickSort(p,n,c,in,i,r);
}

void insertionSort(int*p,int n,int*c,int*in)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        j=i-1;
        while(j>=0&&p[j]>p[j+1])
        {
            swap(&p[j],&p[j+1]);
            *in=*in+1;
            j--;
            *c=*c+1;
        }
        *c=*c+1;
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    printf("Task 8\n");
    int ok=1,i,n,*p1,*p2,*p3,c1=0,c2=0,c3=0,in1=0,in2=0,in3=0;
    while(ok)
    {
        c1=c2=c3=in1=in2=in3=0;
        printf("Введите количество элементов массива\n");
        scanf("%d",&n);
        p1=(int*)malloc(n*sizeof(int));
        p2=(int*)malloc(n*sizeof(int));
        p3=(int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
        {
            printf("Введите элемент массива\n");
            scanf("%d",&p1[i]);
            p2[i]=p1[i];
            p3[i]=p1[i];
        }
        printf("\nНачальный массив: ");
        for(i=0;i<n;i++)printf("%d ",p1[i]);

        bubbleSort(p1,n,&c1,&in1);
        printf("\nПузырек(%d - сравнения, %d - перестановки):\n",c1,in1);
        for(i=0;i<n;i++)printf("%d ",p1[i]);

        quickSort(p2,n,&c2,&in2,0,n-1);
        printf("\nquickSort(%d - сравнения, %d - перестановки):\n",c2,in2);
        for(i=0;i<n;i++)printf("%d ",p1[i]);

        insertionSort(p3,n,&c3,&in3);
        printf("\ninsertionSort(%d - сравнения, %d - перестановки):\n",c3,in3);
        for(i=0;i<n;i++)printf("%d ",p1[i]);
        free(p1);
        free(p2);
        free(p3);

        printf("\nВведите 0(выход) или 1(продолжить)\n");
        scanf("%d",&ok);
    }
    return 0;
}

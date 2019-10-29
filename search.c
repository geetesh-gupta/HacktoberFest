#include <stdio.h>

int linearsearch(int *arr, int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
       {
           if (arr[i] == x)
            {return i;}
       }
    return -1;
}


int binarySearch(int *arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;


        if (arr[mid] == x)
            return mid;


        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);


        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int min(int x, int y) { return (x<=y)? x : y; }

int fibonacciSearch(int *arr, int x, int n)
{
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM  = fibMMm2 + fibMMm1;
    }

    int offset = -1;


    while (fibM > 1)
    {
        int i = min(offset+fibMMm2, n-1);

        if (arr[i] < x)
        {
            fibM  = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }

        else if (arr[i] > x)
        {
            fibM  = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }


        else return i;
    }


    if(fibMMm1 && arr[offset+1]==x)return offset+1;

    return -1;
}

int ternarySearch(int l, int r, int key, int *arr)
{
    if (r >= l)
    {

        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] == key)
        {
            return mid1;
        }
        if (arr[mid2] == key)
        {
            return mid2;
        }

        if (key < arr[mid1])
        {

            return ternarySearch(l, mid1 - 1, key, arr);
        }
        else if (key > arr[mid2])
        {

            return ternarySearch(mid2 + 1, r, key, arr);
        }
        else
        {

            return ternarySearch(mid1 + 1, mid2 - 1, key, arr);
        }
    }
      return -1;
}
int main()
{
    int size;
    int choice;
    int search_Element;
    int result;
    int i;
    int j;
    printf("Enter the size of the array\n");
    scanf("%d",&size);
    int a[20];
    printf("Start entering the array\n");

    for (i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The Entered array is\n");

    for (j=0;j<size;j++)
    {
        printf("%d\n",a[j]);
    }
    printf("Enter which search you want to apply?\n\n\n");
    printf("1.Linear Search\n\n");
    printf("2.Binary Search\n\n");
    printf("3.Ternary Search\n\n");
    printf("4.Fibonacci Search\n\n");

    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Enter the search Element\n");
        scanf("%d",&search_Element);
        result=linearsearch(a, size, search_Element);
        if(result!=-1)
        {
            printf("The number found at location %d\n",result);
        }
        else
        {
            printf("The required number is not in the list\n");
        }
        break;

    case 2:
        printf("Enter the search Element\n");
        scanf("%d",&search_Element);
        result=binarySearch(a,1, size, search_Element);
        if(result!=-1)
        {
            printf("The number found at location %d\n",result);
        }
        else
        {
            printf("The required number is not in the list\n");
        }
        break;

    case 3:
        printf("Enter the search Element\n");
        scanf("%d",&search_Element);
        result=ternarySearch(1, size,search_Element, a);
        if(result!=-1)
        {
            printf("The number found at location %d\n",result);
        }
        else
        {
            printf("The required number is not in the list\n");
        }
        break;

    case 4:
        printf("Enter the search Element\n");
        scanf("%d",&search_Element);
        result=fibonacciSearch(a, search_Element, size);
        if(result!=-1)
        {
            printf("The number found at location %d\n",result);
        }
        else
        {
            printf("The required number is not in the list\n");
        }
        break;

    }

}


#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

FILE *fp1,*fp2,*fp3;
int a[1000],n;
void random(int p,int q)
{
    int i,k;
    fp1 = fopen("input.txt","w");

    if(fp1==NULL)
    {
        printf("ERROR creating file");
        exit(0);
    }

    for(i=0;i<n;i++)
    {
        k=(rand()%(q-p+1))+p;
        fprintf(fp1,"%d ",k);
    }
    fprintf(fp1,"\n");
    fclose(fp1);
    read();
}

void read()
{
    int i=0;
    fp1 = fopen("input.txt","r");
    if(fp1==NULL)
    {
        printf("File Not Found\n");
        return;
    }

    while(!feof(fp1)) //check file encountered or not
    {
        fscanf(fp1,"%d",&a[i]);
        i++;
    }
    printf("\n\nRANDOM ARRAY ELEMENTS BEFORE SORTING\n");
    display();
    fclose(fp1);
}

void write(int c)
{
    int i;
    fp2 = fopen("output.txt","a");
    if(fp2==NULL)
    {
        printf("ERROR creating file\n");
        exit(0);
    }
 switch(c)
    {
        case 1:  fprintf(fp2,"1. MERGE SORT\n");break;
        case 2:  fprintf(fp2,"2. BUBBLE SORT\n");break;
        case 3:  fprintf(fp2,"3. SELECTION SORT\n");break;
        default: printf("INVALID INPUT\n");
    }
    for(i=0;i<n;i++)
        fprintf(fp2,"%d\t",a[i]);
    fprintf(fp2,"\n\n");
    fclose(fp2);
}

void log(c)
{
    float t;
    fp3 = fopen("log.txt","a");
    if(fp2==NULL)
    {
        printf("ERROR creating file\n");
        exit(0);
  switch(c)
    {
        case 1: t = n*(log10(n));
                 fprintf(fp3,"1. MERGE SORT\nInput(n): %d\nTime Efficiency: %.4f\n\n",n,t);
                 break;
        case 2 : t = n*n;
                 fprintf(fp3,"2. BUBBLE SORT\nInput(n): %d\nTime Efficiency: %.4f\n\n",n,t);
                 break;
        case 3 : t = n*n;
                 fprintf(fp3,"3. SELECTION SORT\nInput(n): %d\nTime Efficiency: %.4f\n\n",n,t);
                 break;
        default : printf("INVALID INPUT\n");
    }
}

void display()
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void swap(int b,int c)
{
    int d;
    d=a[b];
    a[b]=a[c];
    a[c]=d;
}

void mergesort(int l,int r)
{
    if(l<r)
    {
        int m = l+(r-l)/2;
        mergesort(l,m);
        mergesort(m+1,r);
        Merge(l,m,r);
    }
}

void Merge(int l,int m,int r)
{
    int n1,n2,i,j,k;
    n1=m-l+1;
    n2=r-m;
    int L[n1],R[n2];

    for(i=0;i<n1;i++)
        L[i]=a[l+i];
    for(i=0;i<n2;i++)
        R[i]=a[m+1+i];
    i=j=0;
    k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;k++;
    }
}

void bubble_sort()
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
                swap(j,j+1);
        }
    }
}

void selection_sort()
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }
       swap(i,min);
    }
}

int main()
{
    int p,q;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    printf("Enter range:\nLower and Upper\n");
    scanf("%d%d",&p,&q);
    srand(time(0));
    fp2 = fopen("output.txt","w");
    fp3 = fopen("log.txt","w");
    fprintf(fp3,"Time Complexity for different Sorting Techniques (Worst Case Analysis):\n\n");

    random(p,q);
    printf("1. MERGE SORT:\n");
    mergesort(0,n-1);
    write(1);
    log(1);
    display();

    random(p,q);
    printf("2. BUBBLE SORT:\n");
    bubble_sort();
    write(2);
    log(2);
    display();

    random(p,q);
    printf("3. SELECTION SORT:\n");
    selection_sort();
    write(3);
    log(3);
    display();
}

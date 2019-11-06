#include<stdio.h>

void quicksort (int arr[],int left,int right){
if(left<right){
int p= partition(arr,left,right);
quicksort(arr,left,p-1);
quicksort(arr,p+1,right);
}
}



int partition(int arr[], int left,int right)
{

int p = arr[left],l= left,r =right,temp;

while(l<r)
{
while(l<right && arr[l]<=p)l++;
while(r>left && arr[r]>=p)r--;
if(l<r)
{
int temp = arr[l];
arr[l] = arr[r];
arr[r] = temp;

}
arr[left] = arr[r];
arr[r]= p;
return r;
}
}
main()
{
int a[20],n,i;

printf("enter the n value");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("enter the integer value");
scanf("%d",&a[i]);
}

printf("before sorting\n");
 for(i=0;i<n;i++)

printf("%d\n",a[i]);

printf("\n");

quicksort(a,0,n-1);

printf("after sorting....\n");

for(i=0;i<n;i++)

printf("%d\n",a[i]);

printf("\n");
}


#include <bits/stdc++.h>
#include <cstdlib>
#include <sys/time.h>
using namespace std;
void InsertionSort(int arr[], int n)
{
int i, key, j;
for (i = 1; i < n; i++)
{
key = arr[i];
j = i - 1;
while (j >= 0 && arr[j] > key)
{
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}
void printArr(int arr[], int n)
{
int i;
for (i = 0; i < n; i++)
cout << arr[i] << " ";
cout << endl;
}
int main(){
srand((unsigned) time(NULL));
int n = 5, count;
float c1 = 0.00, c2 = 0.00, n0 = 0.00;
int size[50];
float tn[50], tp[50];
for(count = 1; count <= 50 ; count++){
n = 10 * count;
size[count-1] = n;
tn[count-1] = (float)(n * n + n - 2) / (float)2;
c1 = 1.00 / 2.00;
c2 = 1.00 / 2.00;
n0 = -2.00 / 2.00;
int *arr = new int[n];
for(int j = 0 ; j < n ;j++){
int random = 1 + (rand() + n);
arr[j] = random;
}
struct timeval start, end;
// start timer.
gettimeofday(&start, NULL);
// unsync the I/O of C++.
ios_base::sync_with_stdio(false);
InsertionSort(arr, n);
// stop timer.
gettimeofday(&end, NULL);
// Calculating total time taken by the program.
double time_taken;
time_taken = (end.tv_sec - start.tv_sec) * 1e6;
time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
tp[count-1] = time_taken;
}
cout<<"The constants are : "<<"c1 = "<<c1<<" c2 = "<<c2<<" n0 = "<<n
0<<endl;
cout<<"S.No."<<"\t"<<"Size(n)"<<"\t"<<"T(n)"<<"\t\t"<<"t(p) in secon
ds"<<endl;
for(int i = 0 ; i < 50 ;i++){
printf("%d\t%d\t%f\t%f\n",(i+1),size[i], tn[i], tp[i]);
}
}

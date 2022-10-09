#include<iostream>
using namespace std;
// Matrix Mi has dimension p[i-1] x p[i] for i = 1..n
int mco(int p[], int n)
{
/* For simplicity of the program, one extra row and one extra column are alloc
ated in
dp[][]. 0th row and 0th column of dp[][] are not used */
int dp[n][n];
/* dp[i, j] = Minimum number of scalar multiplications needed to compute the m
atrix M[i]M[i+1]...M[j]
= M[i..j] where dimension of M[i] is p[i-1] x p[i] */
// cost is zero when multiplying one matrix.
for (int i=1; i<n; i++)
dp[i][i] = 0;
// Simply following above recursive formula.
for (int L=1; L<n-1; L++)
for (int i=1; i<n-L; i++)
dp[i][i+L] = min(dp[i+1][i+L] + p[i-1]*p[i]*p[i+L],
dp[i][i+L-1] + p[i-1]*p[i+L-1]*p[i+L]);
return dp[1][n-1];
}
// Driver code
int main()
{
int n;
cout<<"Enter no. of matrices: "<<" ";
cin>>n;
int dimensions[2*n];
int k = 0;
for(int i = 0 ;i < n ;i++){
cout<<"For matrix "<<(i+1)<<" , Enter dimensions: "<<" ";
cin>>dimensions[k]>>dimensions[k+1];
k = k + 2;
}
int arr[n+1];
arr[0] = dimensions[0];
int j = 1;
for (int i = 1; i < (2*n); i = i+2)
{
arr[j] = dimensions[i];
j++;
}
n = n + 1;
printf("Minimum number of multiplications is %d ",
mco(arr, n));
return 0;
}

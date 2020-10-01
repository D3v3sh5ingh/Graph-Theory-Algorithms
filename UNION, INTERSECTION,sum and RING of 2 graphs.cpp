// C++ program to find length of the longest geometric
// progression in a given arr
#include <iostream>
#include <algorithm>
using namespace std;

// Returns length of the longest GP subarr of arr[]
int find_longest_gp(int *v, int n)
{
	if (n == 0 or n == 1 or n == 2)
		return n;
	int i = 0;
	int j = 1;
	int ans = 0;
	while (j < n)
	{
		int r = v[j] / v[i];
		j++;
		int count = 1;
		while (j < n and v[j] == v[j - 1] * r)
		{
			// cout<<v[i]<<" "<<v[j]<<endl;
			count++;
			j++;
		}

		ans = max(count + 1, ans);
		i = j - 1;
		// cout<<v[i]<<" "<<v[j]<<endl;
	}
	return ans;
}

// Driver code
int main()
{
	int arr1[] = {1, 2, 4, 7, 14, 28, 56, 89};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	cout << find_longest_gp(arr1, n1) << "\n";

	int arr2[] = {1, 3, 4, 9, 7, 27};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	cout << find_longest_gp(arr2, n2) << "\n";

	int arr3[] = {2, 3, 5, 7, 11, 13};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	cout << find_longest_gp(arr3, n3) << "\n";

	return 0;
}

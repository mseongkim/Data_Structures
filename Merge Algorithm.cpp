#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#define Max 5
using namespace std;

//sorted merge
void merge_algo(vector<int> &v1, vector<int> &v2, vector<int> &v3, int v1_size, int v2_size)
{
	int index1 = 0, index2 = 0, index3 = 0;

	while (index1 < v1_size && index2 < v2_size)
	{
		if (v1[index1] < v2[index2])
		{
			v3[index3++] = v1[index1++];
		}
		else
		{
			v3[index3++] = v2[index2++];
		}
	}

	if (index1 == v1_size)
	{
		while (index2 < v2_size)
			v3[index3++] = v2[index2++];
	}
	else
	{
		while (index1 < v1_size)
			v3[index3++] = v1[index1++];
	}
}

void main()
{
	vector<int> v1;
	vector<int> v2;
	int v1_size, v2_size, v3_size;

	srand(time(0));
	for (int i = 0; i < Max; i++)
	{
		int random_num = rand() % 100 + 10;
		v1.push_back((i + 3) * 10);
		v2.push_back(random_num);
	}

	v1.pop_back();
	v3_size = v1.size() + v2.size();
	vector<int> v3(v3_size);

	vector<int>::iterator viter;
	cout << "The elements of the vector 1 are ";
	for (viter = v1.begin(); viter != v1.end(); ++viter)
		cout << *viter << " ";
	cout << endl;

	sort(v2.begin(), v2.end());
	cout << "The elements of the vector 2 are ";
	for (viter = v2.begin(); viter != v2.end(); ++viter)
		cout << *viter << " ";
	cout << endl;

	merge_algo(v1, v2, v3, v1.size(), v2.size());

	cout << "The result of Merge Algorithm is ";
	for (viter = v3.begin(); viter != v3.end(); ++viter)
		cout << *viter << " ";
	cout << endl;
}
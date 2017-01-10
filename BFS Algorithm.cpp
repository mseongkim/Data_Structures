#include <iostream>
#include <vector>
#include <queue>
#define MAX 4
using namespace std;

//directed graph
class Algorithm
{

public:    
	int Adj_matrix[MAX][MAX] =
	{ 0,1,0,0,
	0,1,1,1,
	1,0,0,1,
	0,0,1,0,
	};

	//Breadth First Searsh
	void bfs(int starting_point)
	{
		queue<int> q;
		vector<int> visited(MAX, 0), result;
		q.push(starting_point); 
		visited[starting_point] = 1; 

		while (!q.empty())
		{
			int i = q.front();
			result.push_back(i);
			q.pop();

			for (int j = 0; j < MAX; ++j)
			{
				if (Adj_matrix[i][j] && !visited[j])
				{
					q.push(j);
					visited[j] = 1;
					cout << i << "->" << j << endl;
				}
			}
		}

		vector<int>::iterator viter;
		cout << "The result of Breadth First Search Algorithm is ";
		for (viter = result.begin(); viter != result.end(); ++viter)
			cout << *viter << " ";
		cout << endl;
	}
};

void main()
{
	Algorithm b;
	b.bfs(3); //staring point is 3.
}
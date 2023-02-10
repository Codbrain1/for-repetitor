#include <iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {
	ifstream mypotoc("Текстовый документ.txt");
	
	int N = 0;
	string a;
	string b;
	int* arr = new int[N];
	int** mass = new int* [N];
	int* dlina = new int[N];

	for (int i = 0; i < N; i++)
		dlina[i] = 0;

	for (int i = 0; i < N; i++)
		mass[i] = new int[dlina[i]];

	int index = 1;
	int j = 0;
	bool zavis = false;
	int n = 1;
	while (getline(mypotoc, a))
	{
		

		N++;
		
		for (int i = 0; i < a.length(); i++)
		{
			if (zavis == false) {
				if (a[i] == ';')
				{
					if (j == 0) {
						index = stoi(b);
						b = "";
					}
					else if (j == 1)
					{
						arr[index - 1] = stoi(b);
						b = "";
					}
					j++;
				}
				else 
				if (a[i]!='"' && j==2)
					{
							b = a[i];
							dlina[index-1] = 1;
							mass[index-1] = new int[dlina[index - 1]];
							mass[index-1][0] = stoi(b);
							b = "";

					}
				else if (a[i] == '"') 
				{
						j = 0;
						zavis = true;
						dlina[index - 1] = n;
						mass[index-1] = new int[dlina[index-1]];
						b = "";
				}
				else if(a[i]!=';')
				{
					b += a[i];
				}
			}
			else if (a[i] != '"')
			{

				if (a[i] == ';') {
					n++;
					dlina[index-1]=n;
					mass[index-1][n-1] = stoi(b);
					b = "";
				}
				else if(a[i]!='"'){
					b += a[i];
				}
			}else if (a[i] == '"' && n >= 1) {
				n++;
				dlina[index - 1] = n;
				mass[index - 1][n - 1] = stoi(b);
				b = "";
			}

		}
		j = 0;
		zavis = false;
		n = 0;
	}

	int m = 0;
	for (int i = 0; i < N; i++) {
		if (mass[i][0] != 0) {
			for (int j = 0; j < dlina[i]; j++)
			{
				if (m < arr[mass[i][j] - 1]) {
					m = arr[mass[i][j] - 1];
				}
			}
			arr[i] += m;
		}
	}
	int S = 0;
	for (int i = 0; i < N; i++)
		if (arr[i] > S)
			S = arr[i];
	std::cout << endl << S;

	return 0;
}
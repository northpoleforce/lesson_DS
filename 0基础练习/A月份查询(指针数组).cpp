#include <iostream>

using namespace std;


int main()
{
	string months[13] = { "", "January","February","March","April","May","June","July","August","September","October","November","December" };
	string* ptr[13];
	ptr[0] = NULL;
	for (int i = 1; i <= 12; ++i)
		ptr[i] = &months[i];
	int t; cin >> t;
	int m;
	while (t--)
	{
		cin >> m;
		if (m < 1 || m > 12)
			cout << "error\n";
		else
			cout << *ptr[m] << "\n";
	}

	return 0;
}
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main()
{
	ofstream out("trying.txt");
	if (out.is_open())
		out << "Is it working?" << endl;
	else out << "Apparently not" << endl;
	out.close();

	ifstream in;
	string text = "";
	in.open("trying.txt");
	if (in.is_open())
	{
		while (getline(in, text))
		{
			cout << text;
		}
	}
	in.close();

	return 0;

}
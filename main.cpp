#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include "CommandExecuter.h";
using namespace std;

int main()
{
	CommandExecuter c;
	c.start();


	/*ofstream out("trying.txt");
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
	in.close();*/

}
#define _CRT_SECURE_NO_WARNINGS
#include "QInt.h"
#include <sstream>
#include <conio.h>
#include <fstream>
#include <vector>
int main(int argc, char* argv[])
{
	fstream FileIn;
	FileIn.open(argv[1], ios::in);
	// FileIn.open("QInt_input.txt",ios::in); 
	if (!FileIn)
		cout << "Loi";
	fstream FileOut;
	FileOut.open(argv[2], ios::out);
	//FileIN.open("QInt_output.txt",ios::out);
	while (!FileIn.eof())
	{
		string base;
		getline(FileIn, base);//doc 1 dong trong file
		vector <string> s;
		string delimiter = " ";
		size_t pos = 0;
		string token;
		while ((pos = base.find(delimiter)) < base.size())//doc tung chuoi trong line
		{
			token = base.substr(0, pos);
			s.push_back(token);
			base.erase(0, pos + delimiter.length());
		}
		s.push_back(base);


		if (s.size() == 3)				//truong hop chi co 3 chuoi
		{
			if (s[1] == "~")			//phep not
			{
				int k = 0;
				stringstream geek(s[0]);//chuyen string sang int
				geek >> k;
				QInt temp;
				temp.scanQInt(s[2], k);
				temp = ~temp;
				FileOut << temp.CreateBinStr() << endl;
			}
			else						//phep chuyen doi 
			{
				int k1 = 0;
				stringstream geek1(s[0]);//chuyen string sang int
				geek1 >> k1;
				int k2 = 0;
				stringstream geek2(s[1]);//chuyen string sang int
				geek2 >> k2;
				QInt temp;
				temp.scanQInt(s[2], k1);
				if (k2 == 2)			//tu 10,16 sang 2
					FileOut << temp.CreateBinStr() << endl;
				else if (k2 == 10)		//tu 2 sang 10
					FileOut << temp.binToDec(temp) << endl;
				else if (k2 == 16)		//tu 2, 10 sang 16
					FileOut << temp.binToHex(temp) << endl;
			}
		}
		else if (s.size() == 4)			//cac truong hop tinh toan con lai
		{
			int k = 0;
			stringstream geek1(s[0]);	//chuyen string sang int
			geek1 >> k;

			QInt temp1, temp2, temp;
			temp1.scanQInt(s[1], k);	//chuoi 1
			temp2.scanQInt(s[3], k);	//chuoi 2

			if (s[2] == "<")		//< > == <= >=
			{
				if (temp1 < temp2)
					FileOut << "1" << endl;
				else FileOut << "0" << endl;
			}
			else if (s[2] == ">")
			{
				if (temp1 > temp2)
					FileOut << "1" << endl;
				else FileOut << "0" << endl;
			}
			else if (s[2] == "==")
			{
				if (temp1 == temp2)
					FileOut << "1" << endl;
				else FileOut << "0" << endl;
			}
			else if (s[2] == "<=")
			{
				if (temp1 <= temp2)
					FileOut << "1" << endl;
				else FileOut << "0" << endl;
			}
			else if (s[2] == ">=")
			{
				if (temp1 > temp2)
					FileOut << "1" << endl;
				else FileOut << "0" << endl;
			}
			else
			{
				if (s[2] == "+")			// + - * /
				{
					temp = temp1 + temp2;
				}
				else if (s[2] == "-")
				{
					temp = temp1 + temp2;
				}
				else if (s[2] == "*")
				{
					temp = temp1 * temp2;
				}
				else if (s[2] == "/")
				{
					temp = temp1 / temp2;
				}
				else if (s[2] == "&")
				{
					temp = temp1 & temp2;
				}
				else if (s[2] == "|")
				{
					temp = temp1 | temp2;
				}
				else if (s[2] == "^")
				{
					temp = temp1 ^ temp2;
				}
				else if (s[2] == "<<" || s[2] == ">>" || s[2] == "rol" || s[2] == "ror")
				{
					int timeMove = 0;
					stringstream geez(s[3]);	//chuyen string sang int
					geez >> timeMove;
					if (s[2] == "<<")
					{
						temp = temp1 << timeMove;
					}
					else if (s[2] == ">>")
					{
						temp = temp1 >> timeMove;
					}
					else if (s[2] == "rol")
					{
						temp = temp1.rol(timeMove);
					}
					else if (s[2] == "ror")
					{
						temp = temp1.ror(timeMove);
					}
				}
				if (k == 2)				//xuat dang 2
					FileOut << temp.CreateBinStr() << endl;
				else if (k == 10)		//xuat dang 10
					FileOut << temp.binToDec(temp) << endl;
				else if (k == 16)		//xuat dang 16
					FileOut << temp.binToHex(temp) << endl;
			}
		}
		s.clear();
	}
	FileOut.close();
	FileIn.close();
	return 0;
}
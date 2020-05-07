#pragma once
#include <iostream>
#include <string>
#include <bitset>
using namespace std;

#define QINT_SIZE 4
#define HEX_CHARS "0123456789ABCDEF"
const char CHAR_55 = 55;
const char CHAR_48 = 48;

class QInt
{
private:
	int arr[QINT_SIZE];
public:
	QInt();
	~QInt();
	void setBit(int pos, bool value);			// set bit 1 va 0
	bool getBit(int pos) const;					//lay gia tri 1 bit
	bool IsZero() const;						//kiem tra bang 0
	void scanQInt(string src, int base);		//doc tu chuoi 
	QInt toInverse() const;						//chuyen so am sang dang bu 2
	string CreateBinStr() const;				//tao chuoi tu 1 day bit cho truoc
	void printQInt(int base);					//in man hinh gia tri QInt
	bool isNegative() const;					//kiem tra so am
	QInt decToBin(string src);					//thap phan sang nhi phan
	QInt hexToBin(string src);					//thap luc phan sang nhi phan
	string multipleByTwo(string src, int add);	//nhan mot chuoi voi 2
	string binToDec(const QInt& src);			//nhi phan sang thap phan
	string binToHex(const QInt& src);			//nhi phan sang thap luc phan
	void mergeByFourBit(string a, string& b);	// nhom 4 bit

	QInt operator & (const QInt&);
	QInt operator | (const QInt&);
	QInt operator ^ (const QInt&);
	QInt operator ~();

	bool operator == (const QInt&);
	bool operator != (const QInt&);
	QInt& operator = (const QInt&);
	bool operator < (const QInt&);
	bool operator > (const QInt&);
	bool operator <=(const QInt&);
	bool operator >= (const QInt&);

	QInt operator +(const QInt&);
	QInt operator -(const QInt&);
	QInt operator * (const QInt&);
	QInt operator / (const QInt&);

	QInt operator <<(int);
	QInt operator >>(int);

	QInt rol();
	QInt ror();
	QInt rol(int);
	QInt ror(int);

};


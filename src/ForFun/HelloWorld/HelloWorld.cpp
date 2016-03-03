// HelloWorld.cpp : Defines the entry point for the console application.
//
#include "..\LeoLibrary\LeoLibrary.h"
#include "stdafx.h"
#include <iostream>

using namespace std;
using namespace LeoLibrary;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Hello world!" << endl;
	cout << "Hello world, again!" << endl;
	cout << "Hello world, again and again!" << endl;
	ObjTwo *ot = new ObjTwo();
	ot->m_iCount = 199;
	ot->m_cSymbol = 'q';
	cout << "Count : " << ot->getCount() << endl;
	cout << "Symbol : " << ot->getSymbol() << endl;
	return 0;
}


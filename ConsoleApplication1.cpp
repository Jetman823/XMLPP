// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "XMLDocument.h"
#include <chrono>

using namespace std;
int main(int argc, char** argv)
{
	XMLErr err;

	XMLDocument doc(ReadFlags::IgnoreComments | ReadFlags::IgnoreDecl);

	basic_ifstream<char> stream("Mansion.RS.xml", ios::binary);
	if (!stream)
		throw runtime_error(string("cannot open file "));
	stream.unsetf(ios::skipws);

	// Determine stream size
	stream.seekg(0, ios::end);
	size_t size = stream.tellg();
	stream.seekg(0);

	// Load data and add terminating 0
	string m_data = "";
	m_data.resize(size + 1);
	stream.read(&m_data.front(), static_cast<streamsize>(size));
	m_data[size] = 0;

	ERR result = doc.Parse(m_data);
	doc.Close();

	system("PAUSE");

	return 0;
}


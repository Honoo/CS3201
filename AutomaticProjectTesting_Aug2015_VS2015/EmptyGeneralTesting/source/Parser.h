#pragma once

#ifndef Parser_HEADER
#define Parser_HEADER

#include <string>
#include <vector>

using namespace std;

class Parser
{
public:
	Parser();
	vector<string> parseSimpleProgram(string filename);

private:
	vector<string> split(string str, char delimiter);
	vector<string> splitByDelimiter(vector<string> original, char delimiter);
	vector<string> splitByDelimiters(vector<string> program);
	vector<string> readProgram(string file);
};

#endif
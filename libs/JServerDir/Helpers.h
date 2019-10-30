#pragma once
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <regex>

std::vector<std::string> splitByCharacter(std::string input, char character)
{
	std::stringstream test(input);
	std::string segment;
	std::vector<std::string> seglist;

	while (std::getline(test, segment, character))
	{
		seglist.push_back(segment);
	}

	return seglist;
}

//
// Highly specialized for server query results, will fix later
//
std::map<std::string, std::string> splitResultsToMap(std::string input)
{
	std::map<std::string, std::string> splitMap;
	std::string pattern = "\\\\([\\d\\w\\.\\s]*)\\\\([\\d\\w\\.\\s]*)";
	std::regex commandRegex(pattern);
	std::smatch match;

	std::string searchString = input;

	while (std::regex_search(searchString, match, commandRegex)) {

		splitMap.insert({ match[1], match[2] });
		searchString = match.suffix().str();
	}
	
	return splitMap;
}
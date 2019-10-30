#pragma once
#include <vector>
#include <map>
#include <string>
#include <regex>

std::vector<std::string> split(std::string stringToBeSplitted, std::string delimeter)
{
	std::vector<std::string> splittedString;
	int startIndex = 0;
	int  endIndex = 0;
	while ((endIndex = stringToBeSplitted.find(delimeter, startIndex)) < stringToBeSplitted.size())
	{
		std::string val = stringToBeSplitted.substr(startIndex, endIndex - startIndex);
		splittedString.push_back(val);
		startIndex = endIndex + delimeter.size();
	}
	if (startIndex < stringToBeSplitted.size())
	{
		std::string val = stringToBeSplitted.substr(startIndex);
		splittedString.push_back(val);
	}
	return splittedString;
}

//
// Highly specialized for server query results, will fix later
//
std::map<std::string, std::string> splitResultsToMap(std::string input)
{
#if 1
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
#else
	std::map<std::string, std::string> splitMap;

	int startIndex = 0;
	int  endIndex = 0;

	std::string key = "";
	std::string value = "";

	while ((endIndex = input.find(delimeter, startIndex)) < input.size())
	{
		if (startIndex == 0) {
			startIndex = endIndex + delimeter.size();
			continue;
		}

		if (key.empty()) {
			key = input.substr(startIndex, endIndex - startIndex);
		}
		else {
			value = input.substr(startIndex, endIndex - startIndex);
		}

		startIndex = endIndex + delimeter.size();

		// If we've got a matching key/value pair, 
		if (!key.empty() && !value.empty()) {
			splitMap.insert({ key, value });
			key = "";
			value = "";
		}
	}


	if (startIndex < input.size())
	{
		value = input.substr(startIndex);

		// If we've got a matching key/value pair, 
		if (!key.empty() && !value.empty()) {
			splitMap.insert({ key, value });
			key = "";
			value = "";
		}
	}



	return splitMap;
#endif
}
#include <vector>
#include <string>
#include <iostream>

#include "../sql/commands/commands.h"

#include "tokenize.h"
#include "grab.h"
#include "../swc.h"

bool swc::isAhead(std::string expectedStr, std::string str, size_t index)
{
	int successfulChecks = 0;
	for (size_t zeroIndex = 0; zeroIndex < expectedStr.size(); ++zeroIndex, ++index) {
		if (str.at(index) == expectedStr.at(zeroIndex))
			++successfulChecks;
		else
			break;
	}
	return successfulChecks == expectedStr.size();
}

void swc::tokenizer(std::string tokens)
{
	std::string title, link;
	for (size_t index = 0; index < tokens.size(); ++index) {
		if (swc::isAhead("href", tokens, index) or swc::isAhead("HREF", tokens, index)) {
			index += 6;
			for (; tokens.at(index) != '"'; ++index) {
				link += std::string(1, tokens.at(index));
			}
			std::string newstr;
			if (link.size() > 8) {
				if (swc::isAhead("https://", link, 0)) {
					for (size_t i = 8; i < link.size(); ++i) {
						newstr += link.at(i);
					}
					link = newstr;
				}
				if (swc::isAhead("http://", link, 0)) {
					for (size_t i = 7; i < link.size(); ++i) {
						newstr += link.at(i);
					}
					link = newstr;
				}
			}
			if (link.size() > 2) {
				if (swc::isAhead("//", link, 0)) {
					for (size_t i = 2; i < link.size(); ++i) {
						newstr += link.at(i);
					}
					link = newstr;
				}
			}
			bool isURL = false;
			for (size_t i = 0; i < link.size(); ++i) {
				if (link.at(i) == '.') {
					isURL = true;
					break;
				}
			}
			if (!isURL) {
				if (link.at(0) == '/') {
					swc::cmds::insert(swc::getWebsiteTitle(swc::rootDomain + link), swc::rootDomain + link);
				}
				else {
					swc::cmds::insert(swc::getWebsiteTitle(swc::rootDomain + "/" + link), swc::rootDomain + "/" + link);
				}
			}
			else {
				swc::cmds::insert(swc::getWebsiteTitle(link), link);
			}
			title.clear();
			link.clear();
		}
	}
}


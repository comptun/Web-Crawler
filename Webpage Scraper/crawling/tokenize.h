#pragma once

namespace swc {
	class token {
	public:
		std::string title;
		std::string link;
	};
	bool isAhead(std::string expectedStr, std::string str, size_t index);
	void tokenizer(std::string tokens);
}
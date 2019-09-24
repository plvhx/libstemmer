#ifndef _STRING_UTIL_HPP_
#define _STRING_UTIL_HPP_

#include <string>
#include <vector>

namespace stemmer {

class StringUtil
{
public:
	std::string tolower(std::string buf_);
	void trim(std::string& buf_);
	void rtrim(std::string& buf_);
	void ltrim(std::string& buf_);
	std::string normalize(std::string buf_);
	std::vector<std::string> split(std::string delim_, std::string buf_);
};

}

#endif /* _STRING_UTIL_HPP_ */
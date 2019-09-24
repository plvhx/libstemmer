#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <pcrecpp.h>
#include <bits/stdc++.h>
#include <stemmer/string-util.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer;

string StringUtil::tolower(string buf_)
{
	string res_ = buf_;

	::transform(res_.begin(), res_.end(), res_.begin(), ::tolower);

	return res_;
}

void StringUtil::trim(string& buf_)
{
	buf_.erase(buf_.find_last_not_of("\t\n\v\f\r ") + 1)
		.erase(0, buf_.erase(buf_.find_last_not_of("\t\n\v\f\r ") + 1)
			.find_first_not_of("\t\n\v\f\r "));
}

void StringUtil::rtrim(string& buf_)
{
	buf_.erase(buf_.find_last_not_of("\t\n\v\f\r ") + 1);
}

void StringUtil::ltrim(string& buf_)
{
	buf_.erase(0, buf_.find_first_not_of("\t\n\v\f\r "));
}

string StringUtil::normalize(string buf_)
{
	string res_;

	// step 1
	res_ = tolower(buf_);
	// step 2
	RE("[^a-z0-9 \\-]", RE_Options(PCRE_CASELESS | PCRE_MULTILINE)).GlobalReplace(string(" "), &res_);
	// step 3
	RE("( +)", RE_Options(PCRE_CASELESS | PCRE_MULTILINE)).GlobalReplace(string(" "), &res_);

	trim(res_);

	return res_;
}

vector<string> StringUtil::split(string delim_, string buf_)
{
	unsigned int left_ = 0, right_ = 0;
	unsigned int dlen_ = delim_.size(), slen_ = buf_.size();
	vector<string> vres_;

	if (buf_.empty())
		return vres_;

	trim(buf_);

	do {
		right_ = buf_.find(delim_, left_);
		vres_.push_back(buf_.substr(left_, right_ - left_));
		left_ = right_ + dlen_;
	} while (right_ < slen_);

	return vres_;
}
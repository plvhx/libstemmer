#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-38a.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule38aTest, Matching)
{
	Rule38a rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("pelawat", rbuf_)); ASSERT_EQ("pelawat", rbuf_); }
}
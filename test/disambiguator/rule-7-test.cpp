#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-7.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule7Test, Matching)
{
	Rule7 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("terperuk", rbuf_)); ASSERT_EQ("peruk", rbuf_); }
}
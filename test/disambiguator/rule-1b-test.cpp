#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-1b.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule1bTest, Matching)
{
	Rule1b rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("berakit", rbuf_)); ASSERT_EQ("rakit", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("bertabur", rbuf_)); }
}
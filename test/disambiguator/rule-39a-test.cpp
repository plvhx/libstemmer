#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-39a.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule39aTest, Matching)
{
	Rule39a rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("pemain", rbuf_)); ASSERT_EQ("pemain", rbuf_); }
}
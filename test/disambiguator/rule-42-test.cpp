#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-42.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule42Test, Matching)
{
	Rule42 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("kaumiliki", rbuf_)); ASSERT_EQ("miliki", rbuf_); }
}
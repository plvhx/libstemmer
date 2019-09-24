#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-9.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule9, Matching)
{
	Rule9 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("teterbang", rbuf_)); ASSERT_EQ("terbang", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("terperuk", rbuf_)); }
}
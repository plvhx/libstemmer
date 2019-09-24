#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-8.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule8Test, Matching)
{
	Rule8 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("tertangkap", rbuf_)); ASSERT_EQ("tangkap", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("teracun", rbuf_)); }
	{ ASSERT_FALSE(rule_.disambiguate("terperuk", rbuf_)); }
}
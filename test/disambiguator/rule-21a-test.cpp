#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-21a.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule21aTest, Matching)
{
	Rule21a rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("peradilan", rbuf_)); ASSERT_EQ("adilan", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("perundikan", rbuf_)); ASSERT_EQ("undikan", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("perjudikan", rbuf_)); }
}
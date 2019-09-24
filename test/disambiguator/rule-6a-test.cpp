#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-6a.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule6aTest, Matching)
{
	Rule6a rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("terancam", rbuf_)); ASSERT_EQ("ancam", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("terbalik", rbuf_)); }
}
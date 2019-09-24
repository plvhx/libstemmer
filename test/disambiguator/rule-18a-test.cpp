#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-18a.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule18aTest, Matching)
{
	Rule18a rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("menyala", rbuf_)); ASSERT_EQ("nyala", rbuf_); }
}
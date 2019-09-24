#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-17a.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule17aTest, Matching)
{
	Rule17a rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("mengerat", rbuf_)); ASSERT_EQ("erat", rbuf_); }
}
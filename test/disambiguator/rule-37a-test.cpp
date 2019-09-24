#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-37a.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule37aTest, Matching)
{
	Rule37a rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("perang", rbuf_)); ASSERT_EQ("perang", rbuf_); }
}
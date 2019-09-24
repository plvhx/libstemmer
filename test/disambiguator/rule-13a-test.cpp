#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-13a.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule13aTest, Matching)
{
	Rule13a rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("memasuki", rbuf_)); ASSERT_EQ("masuki", rbuf_); }
}
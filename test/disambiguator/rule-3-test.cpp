#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-3.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule3Test, Matching)
{
	Rule3 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("berhierarki", rbuf_)); ASSERT_EQ("hierarki", rbuf_); }
}
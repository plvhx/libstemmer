#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-24.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule24Test, Matching)
{
	Rule24 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("perdaerah", rbuf_)); ASSERT_EQ("daerah", rbuf_); }
}
#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-23.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule23Test, Matching)
{
	Rule23 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("pertahan", rbuf_)); ASSERT_EQ("tahan", rbuf_); }
}
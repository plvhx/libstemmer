#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-17d.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule17dTest, Matching)
{
	Rule17d rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("mengerikan", rbuf_)); ASSERT_EQ("ngerikan", rbuf_); }
}
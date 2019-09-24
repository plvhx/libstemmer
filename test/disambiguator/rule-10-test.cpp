#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-10.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule10Test, Matching)
{
	Rule10 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("melalui", rbuf_)); ASSERT_EQ("lalui", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("meracuni", rbuf_)); ASSERT_EQ("racuni", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("mewarnai", rbuf_)); ASSERT_EQ("warnai", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("meyakini", rbuf_)); ASSERT_EQ("yakini", rbuf_); }
}
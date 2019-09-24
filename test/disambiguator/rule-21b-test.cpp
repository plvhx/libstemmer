#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-21b.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule21bTest, Matching)
{
	Rule21b rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("perusak", rbuf_)); ASSERT_EQ("rusak", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("perancang", rbuf_)); ASSERT_EQ("rancang", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("perjudikan", rbuf_)); }
}
#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-31b.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule31bTest, Matching)
{
	Rule31b rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("penyalut", rbuf_)); ASSERT_EQ("salut", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("penyekat", rbuf_)); ASSERT_EQ("sekat", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("penyikat", rbuf_)); ASSERT_EQ("sikat", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("penyukat", rbuf_)); ASSERT_EQ("sukat", rbuf_); }
}
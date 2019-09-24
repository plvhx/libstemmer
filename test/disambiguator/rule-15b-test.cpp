#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-15b.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule15bTest, Matching)
{
	Rule15b rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("menulis", rbuf_)); ASSERT_EQ("tulis", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("menari", rbuf_)); ASSERT_EQ("tari", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("menyayangi", rbuf_)); }
}
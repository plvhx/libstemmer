#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-30b.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule30bTest, Matching)
{
	Rule30b rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("pengawal", rbuf_)); ASSERT_EQ("kawal", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pengetat", rbuf_)); ASSERT_EQ("ketat", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pengira", rbuf_)); ASSERT_EQ("kira", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pengorban", rbuf_)); ASSERT_EQ("korban", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("penguat", rbuf_)); ASSERT_EQ("kuat", rbuf_); }
}
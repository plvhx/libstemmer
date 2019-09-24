#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-39b.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule39bTest, Matching)
{
	Rule39b rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("temali", rbuf_)); ASSERT_EQ("tali", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("gemetar", rbuf_)); ASSERT_EQ("getar", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("gemuruh", rbuf_)); ASSERT_EQ("guruh", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("kemerlip", rbuf_)); ASSERT_EQ("kerlip", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("kemerlap", rbuf_)); ASSERT_EQ("kerlap", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("kemelut", rbuf_)); ASSERT_EQ("kelut", rbuf_); }
}
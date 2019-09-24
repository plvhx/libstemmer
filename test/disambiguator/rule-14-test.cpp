#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-14.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule14Test, Matching)
{
	Rule14 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("mencantum", rbuf_)); ASSERT_EQ("cantum", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("menduduki", rbuf_)); ASSERT_EQ("duduki", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("menjemput", rbuf_)); ASSERT_EQ("jemput", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("mensyukuri", rbuf_)); ASSERT_EQ("syukuri", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("mensyaratkan", rbuf_)); ASSERT_EQ("syaratkan", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("mentaati", rbuf_)); ASSERT_EQ("taati", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("menziarahi", rbuf_)); ASSERT_EQ("ziarahi", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("menyayangi", rbuf_)); }
}
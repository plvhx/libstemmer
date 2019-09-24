#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-27.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule27Test, Matching)
{
	Rule27 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("pencari", rbuf_)); ASSERT_EQ("cari", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pendaki", rbuf_)); ASSERT_EQ("daki", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("penjual", rbuf_)); ASSERT_EQ("jual", rbuf_); }
}
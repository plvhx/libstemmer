#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-16.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule16Test, Matching)
{
	Rule16 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("menggunakan", rbuf_)); ASSERT_EQ("gunakan", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("menghambat", rbuf_)); ASSERT_EQ("hambat", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("mengqasar", rbuf_)); ASSERT_EQ("qasar", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("mengkritik", rbuf_)); ASSERT_EQ("kritik", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("mengira", rbuf_)); }
}
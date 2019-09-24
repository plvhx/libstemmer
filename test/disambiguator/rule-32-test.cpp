#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-32.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule32Test, Matching)
{
	Rule32 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("pelajar", rbuf_)); ASSERT_EQ("ajar", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pelayan", rbuf_)); ASSERT_EQ("layan", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("peledak", rbuf_)); ASSERT_EQ("ledak", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pelirik", rbuf_)); ASSERT_EQ("lirik", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pelobi", rbuf_)); ASSERT_EQ("lobi", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pelupa", rbuf_)); ASSERT_EQ("lupa", rbuf_); }
}
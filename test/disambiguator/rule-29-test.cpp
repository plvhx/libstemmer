#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-29.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule29Test, Matching)
{
	Rule29 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("pengganti", rbuf_)); ASSERT_EQ("ganti", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("penghajar", rbuf_)); ASSERT_EQ("hajar", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pengqasar", rbuf_)); ASSERT_EQ("qasar", rbuf_); }
}
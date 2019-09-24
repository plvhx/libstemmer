#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-28b.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule28bTest, Matching)
{
	Rule28b rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("penari", rbuf_)); ASSERT_EQ("tari", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("penerap", rbuf_)); ASSERT_EQ("terap", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("peninggalan", rbuf_)); ASSERT_EQ("tinggalan", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("penolong", rbuf_)); ASSERT_EQ("tolong", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("penulis", rbuf_)); ASSERT_EQ("tulis", rbuf_); }
}
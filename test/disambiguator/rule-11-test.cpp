#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-11.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule11Test, Matching)
{
	Rule11 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("membantu", rbuf_)); ASSERT_EQ("bantu", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("memfasilitasi", rbuf_)); ASSERT_EQ("fasilitasi", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("memvonis", rbuf_)); ASSERT_EQ("vonis", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("mewarnai", rbuf_)); }
}
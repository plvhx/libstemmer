#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-30c.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule30cTest, Matching)
{
	Rule30c rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("pengetahuan", rbuf_)); ASSERT_EQ("tahuan", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pengeblog", rbuf_)); ASSERT_EQ("blog", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pengetest", rbuf_)); ASSERT_EQ("test", rbuf_); }
}
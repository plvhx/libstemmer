#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-12.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule12Test, Matching)
{
	Rule12 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("mempengaruhi", rbuf_)); ASSERT_EQ("pengaruhi", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("memperbaharui", rbuf_)); ASSERT_EQ("perbaharui", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("mewarnai", rbuf_)); }
}
#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-6b.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule6bTest, Matching)
{
	Rule6b rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("teracun", rbuf_)); ASSERT_EQ("racun", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("terbalik", rbuf_)); }
}
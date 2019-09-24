#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-17b.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule17bTest, Matching)
{
	Rule17b rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("mengira", rbuf_)); ASSERT_EQ("kira", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("mengecil", rbuf_)); ASSERT_EQ("kecil", rbuf_); }
}
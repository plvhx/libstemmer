#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-20.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule20Test, Matching)
{
	Rule20 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("pewarna", rbuf_)); ASSERT_EQ("warna", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("peyoga", rbuf_)); ASSERT_EQ("yoga", rbuf_); }
}
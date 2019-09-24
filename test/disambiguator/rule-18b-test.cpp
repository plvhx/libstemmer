#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-18b.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule18bTest, Matching)
{
	Rule18b rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("menyapu", rbuf_)); ASSERT_EQ("sapu", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("menyikat", rbuf_)); ASSERT_EQ("sikat", rbuf_); }
}
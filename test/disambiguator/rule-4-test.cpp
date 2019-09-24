#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-4.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule4Test, Matching)
{
	Rule4 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("belajar", rbuf_)); ASSERT_EQ("ajar", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("bekerja", rbuf_)); }
}
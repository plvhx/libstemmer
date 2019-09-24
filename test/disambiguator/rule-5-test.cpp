#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-5.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule5Test, Matching)
{
	Rule5 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("bekerja", rbuf_)); ASSERT_EQ("kerja", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("belajar", rbuf_)); }
}
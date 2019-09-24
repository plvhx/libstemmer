#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-26a.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule26aTest, Matching)
{
	Rule26a rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("pemilik", rbuf_)); ASSERT_EQ("milik", rbuf_); }
}
#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-15a.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule15aTest, Matching)
{
	Rule15a rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("menikmati", rbuf_)); ASSERT_EQ("nikmati", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("menyayangi", rbuf_)); }
}
#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-26b.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule26bTest, Matching)
{
	Rule26b rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("pemilih", rbuf_)); ASSERT_EQ("pilih", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pemukul", rbuf_)); ASSERT_EQ("pukul", rbuf_); }
}
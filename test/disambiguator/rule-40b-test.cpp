#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-40b.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule40bTest, Matching)
{
	Rule40b rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("kinerja", rbuf_)); ASSERT_EQ("kerja", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("sinambung", rbuf_)); ASSERT_EQ("sambung", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("tinambah", rbuf_)); ASSERT_EQ("tambah", rbuf_); }
}
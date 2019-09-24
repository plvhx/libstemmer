#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-30a.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule30aTest, Matching)
{
	Rule30a rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("pengalihan", rbuf_)); ASSERT_EQ("alihan", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pengeram", rbuf_)); ASSERT_EQ("eram", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pengikat", rbuf_)); ASSERT_EQ("ikat", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pengobat", rbuf_)); ASSERT_EQ("obat", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pengurusan", rbuf_)); ASSERT_EQ("urusan", rbuf_); }
}
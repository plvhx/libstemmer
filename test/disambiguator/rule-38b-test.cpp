#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-38b.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule38bTest, Matching)
{
	Rule38b rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("telunjuk", rbuf_)); ASSERT_EQ("tunjuk", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("geletar", rbuf_)); ASSERT_EQ("getar", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("selidik", rbuf_)); ASSERT_EQ("sidik", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pelatuk", rbuf_)); ASSERT_EQ("patuk", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("telapak", rbuf_)); ASSERT_EQ("tapak", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("gelombang", rbuf_)); ASSERT_EQ("gombang", rbuf_); }
}
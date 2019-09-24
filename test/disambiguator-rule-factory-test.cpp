#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator-rule-factory.hpp>

using namespace std;
using namespace stemmer;
using namespace testing;

TEST(DisambiguatorRuleFactoryTest, ExistenceTest)
{
	DisambiguatorRuleFactory dr_;

	ASSERT_NE(0, dr_.getDisambiguators("rule-1").size());
}

TEST(DisambiguatorRuleFactoryTest, WillThrowException)
{
	DisambiguatorRuleFactory dr_;

	EXPECT_THROW(dr_.getDisambiguators("non-existent-disambiguators"), runtime_error);
}
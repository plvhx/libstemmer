#include <gtest/gtest.h>
#include <stemmer/precedence-adjustor-specification.hpp>

using namespace stemmer;
using namespace testing;

TEST(PrecedenceAdjustorSpecificationTest, EqualityTest)
{
	PrecedenceAdjustorSpecification pa_;

	// rule #1
	ASSERT_TRUE(pa_.isSatisfiedBy("berulah"));
	// rule #2
	ASSERT_TRUE(pa_.isSatisfiedBy("berpergian"));
	// rule #3
	ASSERT_TRUE(pa_.isSatisfiedBy("memakai"));
	// rule #4
	ASSERT_TRUE(pa_.isSatisfiedBy("digauli"));
	// rule #5
	ASSERT_TRUE(pa_.isSatisfiedBy("pemakai"));
	// rule #6
	ASSERT_TRUE(pa_.isSatisfiedBy("terisi"));
}
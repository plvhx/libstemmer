#include <gtest/gtest.h>
#include <stemmer/dictionary.hpp>
#include <stemmer/stopword-remover.hpp>

using namespace stemmer;
using namespace testing;

TEST(StopwordRemoverTest, EqualityTest)
{
	Dictionary *dict_ = new Dictionary();

	dict_->add("di");
	dict_->add("ke");

	StopwordRemover *sr_ = new StopwordRemover(dict_);

	ASSERT_EQ("pergi sekolah", sr_->remove("pergi ke sekolah"));
	ASSERT_EQ("makan rumah", sr_->remove("makan di rumah"));

	delete sr_;
}
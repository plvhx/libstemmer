#include <iostream>
#include <gtest/gtest.h>
#include <stemmer/dictionary.hpp>
#include <stemmer/stemmer.hpp>
#include <stemmer/context/visitor/visitor-provider.hpp>

using namespace std;
using namespace stemmer;
using namespace stemmer::context::visitor;
using namespace testing;

TEST(StemmerTest, StopOnShortWord)
{
	Dictionary *dict_ = new Dictionary();
	VisitorProvider *prov_ = new VisitorProvider();

	dict_->makeFromFile("./kata-dasar.txt");

	Stemmer *stem_ = new Stemmer(dict_, prov_);

	ASSERT_EQ("mei", stem_->stem("mei"));
	ASSERT_EQ("bui", stem_->stem("bui"));

	delete stem_;
	delete prov_;
	delete dict_;
}

TEST(StemmerTest, StopOnFoundOnDictionary)
{
	Dictionary *dict_ = new Dictionary();
	VisitorProvider *prov_ = new VisitorProvider();

	dict_->makeFromFile("./kata-dasar.txt");

	Stemmer *stem_ = new Stemmer(dict_, prov_);

	ASSERT_EQ("nilai", stem_->stem("nilai"));

	delete stem_;
	delete prov_;
	delete dict_;
}
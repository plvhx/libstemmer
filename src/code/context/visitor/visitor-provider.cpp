#include <vector>
#include <stemmer/disambiguator-rule-collect.hpp>
#include <stemmer/disambiguator-rule-factory.hpp>
#include <stemmer/context/visitor/prefix-disambiguator.hpp>
#include <stemmer/context/visitor/unstem-short-word.hpp>
#include <stemmer/context/visitor/remove-derivational-suffix.hpp>
#include <stemmer/context/visitor/remove-inflectional-particle.hpp>
#include <stemmer/context/visitor/remove-inflectional-possessive-pronoun.hpp>
#include <stemmer/context/visitor/remove-plain-prefix.hpp>
#include <stemmer/context/visitor/visitor-provider.hpp>

using namespace std;
using namespace stemmer;
using namespace stemmer::disambiguator;
using namespace stemmer::context::visitor;

VisitorProvider::VisitorProvider()
{
	initVisitors();
}

VisitorProvider::~VisitorProvider()
{
	purgeExistingVisitors();
}

void VisitorProvider::initVisitors()
{
	fact_ = new DisambiguatorRuleFactory();

	// visitors
	visitors_.push_back(new UnstemShortWord());

	// suffix visitors
	suffix_visitors_.push_back(new RemoveInflectionalParticle());
	suffix_visitors_.push_back(new RemoveInflectionalPossessivePronoun());
	suffix_visitors_.push_back(new RemoveDerivationalSuffix());

	// prefix visitors
	prefix_visitors_.push_back(new RemovePlainPrefix());
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-1"), "rule-1"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-2"), "rule-2"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-3"), "rule-3"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-4"), "rule-4"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-5"), "rule-5"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-6"), "rule-6"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-7"), "rule-7"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-8"), "rule-8"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-9"), "rule-9"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-10"), "rule-10"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-11"), "rule-11"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-12"), "rule-12"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-13"), "rule-13"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-14"), "rule-14"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-15"), "rule-15"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-16"), "rule-16"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-17"), "rule-17"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-18"), "rule-18"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-19"), "rule-19"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-20"), "rule-20"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-21"), "rule-21"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-23"), "rule-23"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-24"), "rule-24"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-25"), "rule-25"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-26"), "rule-26"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-27"), "rule-27"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-28"), "rule-28"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-29"), "rule-29"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-30"), "rule-30"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-31"), "rule-31"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-32"), "rule-32"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-34"), "rule-34"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-35"), "rule-35"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-36"), "rule-36"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-37"), "rule-37"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-38"), "rule-38"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-39"), "rule-39"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-40"), "rule-40"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-41"), "rule-41"));
	prefix_visitors_.push_back(new PrefixDisambiguator(fact_->getDisambiguators("rule-42"), "rule-42"));
}

template<class T>
void VisitorProvider::destroyVisitor(vector<T *>& ida_)
{
	while (!ida_.empty()) {
		delete ida_.back();
		ida_.pop_back();
	}

	ida_.clear();
}

void VisitorProvider::purgeExistingVisitors()
{
	// visitors
	destroyVisitor<VisitorAbstract>(visitors_);

	// prefix visitors
	destroyVisitor<VisitorAbstract>(prefix_visitors_);

	// suffix visitors
	destroyVisitor<VisitorAbstract>(suffix_visitors_);

	// free unused factory
	delete fact_;
}

vector<VisitorAbstract *>& VisitorProvider::getVisitors()
{
	return visitors_;
}

vector<VisitorAbstract *>& VisitorProvider::getPrefixVisitors()
{
	return prefix_visitors_;
}

vector<VisitorAbstract *>& VisitorProvider::getSuffixVisitors()
{
	return suffix_visitors_;
}
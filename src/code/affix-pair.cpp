#include <string>
#include <vector>
#include <pcrecpp.h>
#include <stemmer/affix-pair.hpp>

using namespace pcrecpp;
using namespace stemmer;
using namespace std;

AffixPair::AffixPair()
{
}

AffixPair::~AffixPair()
{
}

bool AffixPair::conditionToTerminate(string buf_)
{
	return (!RE("^me(.*)kan$").FullMatch(buf_) ? true : false);
}

bool AffixPair::lookupRule(string buf_, string reg_)
{
	return RE(reg_).FullMatch(buf_);
}

bool AffixPair::isSatisfiedBy(string buf_)
{
	int contains_ = 0;
	vector<string> regex_{
		"ber(.*)i",
		"di(.*)an",
		"ke(.*)i",
		"ke(.*)an",
		"me(.*)an",
		"ter(.*)an",
		"per(.*)an"
	};

	if (conditionToTerminate(buf_) && buf_ != "ketahui") {
		for (unsigned i = 0; i < regex_.size(); i++) {
			contains_ |= (lookupRule(buf_, regex_[i]) ? 1 : 0);
		}
	}

	return (!contains_ ? false : true);
}
#include <vector>
#include <pcrecpp.h>
#include <stemmer/specification-abstract.hpp>
#include <stemmer/precedence-adjustor-specification.hpp>

using namespace pcrecpp;
using namespace stemmer;
using namespace std;

PrecedenceAdjustorSpecification::PrecedenceAdjustorSpecification()
{
}

PrecedenceAdjustorSpecification::~PrecedenceAdjustorSpecification()
{
}

bool PrecedenceAdjustorSpecification::isSatisfiedBy(string buf_)
{
	vector<RE> regbuf_ = {
		RE("^be(.*)lah$"),
		RE("^be(.*)an$"),
		RE("^me(.*)i$"),
		RE("^di(.*)i$"),
		RE("^pe(.*)i$"),
		RE("^ter(.*)i$")
	};

	for (unsigned i = 0; i < regbuf_.size(); i++) {
		if (regbuf_.at(i).FullMatch(buf_)) {
			return true;
		}
	}

	return false;
}
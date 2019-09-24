#ifndef _AFFIX_PAIR_HPP_
#define _AFFIX_PAIR_HPP_

#include <string>
#include <stemmer/specification-abstract.hpp>

namespace stemmer {

class AffixPair : public SpecificationAbstract
{
protected:
	bool conditionToTerminate(std::string buf_);
	bool lookupRule(std::string buf_, std::string reg_);

public:
	AffixPair();
	~AffixPair();
	
	bool isSatisfiedBy(std::string buf_);
};

}

#endif /* _AFFIX_PAIR_HPP_ */
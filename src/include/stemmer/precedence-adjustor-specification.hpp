#ifndef _PRECEDENCE_ADJUSTOR_SPECIFICATION_HPP_
#define _PRECEDENCE_ADJUSTOR_SPECIFICATION_HPP_

#include <string>
#include <stemmer/specification-abstract.hpp>

namespace stemmer {

class PrecedenceAdjustorSpecification : public SpecificationAbstract
{
public:
	PrecedenceAdjustorSpecification();
	~PrecedenceAdjustorSpecification();

	bool isSatisfiedBy(std::string buf_);
};

}

#endif /* _PRECEDENCE_ADJUSTOR_SPECIFICATION_HPP_ */
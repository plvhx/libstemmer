#ifndef _SPECIFICATION_ABSTRACT_HPP_
#define _SPECIFICATION_ABSTRACT_HPP_

#include <string>

namespace stemmer {

class SpecificationAbstract
{
public:
	virtual bool isSatisfiedBy(std::string buf_) = 0;
};

}

#endif /* _SPECIFICATION_ABSTRACT_HPP_ */
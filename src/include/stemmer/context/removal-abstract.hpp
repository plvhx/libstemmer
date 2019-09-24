#ifndef _REMOVAL_ABSTRACT_HPP_
#define _REMOVAL_ABSTRACT_HPP_

#include <string>

namespace stemmer {
namespace context {

class RemovalAbstract
{
public:
	virtual std::string getSubject() = 0;
	virtual std::string getResult() = 0;
	virtual std::string getRemovedPart() = 0;
	virtual std::string getAffixType() = 0;
};

}
}

#endif /* _REMOVAL_ABSTRACT_HPP_ */
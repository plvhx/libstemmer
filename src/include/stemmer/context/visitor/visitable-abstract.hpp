#ifndef _VISITABLE_ABSTRACT_HPP_
#define _VISITABLE_ABSTRACT_HPP_

#include <stemmer/context/visitor/visitor-abstract.hpp>

namespace stemmer {
namespace context {
namespace visitor {

class VisitableAbstract
{
public:
	virtual void accept(VisitorAbstract *rvisit_) = 0;
};

}
}
}

#endif /* _VISITABLE_ABSTRACT_HPP_ */
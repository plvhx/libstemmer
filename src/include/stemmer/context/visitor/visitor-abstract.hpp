#ifndef _VISITOR_ABSTRACT_HPP_
#define _VISITOR_ABSTRACT_HPP_

#include <stemmer/context/context-abstract.hpp>

namespace stemmer {
namespace context {
namespace visitor {

class VisitorAbstract
{
public:
	virtual void visit(stemmer::context::ContextAbstract& ctx_) = 0;
};

}
}
}

#endif /* _VISITOR_ABSTRACT_HPP_ */
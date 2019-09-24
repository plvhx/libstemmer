#ifndef _REMOVE_DERIVATIONAL_SUFFIX_HPP_
#define _REMOVE_DERIVATIONAL_SUFFIX_HPP_

#include <string>
#include <stemmer/context/visitor/visitor-abstract.hpp>

namespace stemmer {
namespace context {
namespace visitor {

class RemoveDerivationalSuffix : public VisitorAbstract
{
public:
	RemoveDerivationalSuffix();
	~RemoveDerivationalSuffix();
	
	void visit(stemmer::context::ContextAbstract& ctx_);
	std::string removeSuffix(std::string buf_);
};

}
}
}

#endif /* _REMOVE_DERIVATIONAL_SUFFIX_HPP_ */
#ifndef _REMOVE_PLAIN_PREFIX_HPP_
#define _REMOVE_PLAIN_PREFIX_HPP_

#include <stemmer/context/visitor/visitor-abstract.hpp>

namespace stemmer {
namespace context {
namespace visitor {

class RemovePlainPrefix : public VisitorAbstract
{
public:
	RemovePlainPrefix();
	~RemovePlainPrefix();
	
	void visit(stemmer::context::ContextAbstract& ctx_);
	std::string remove(std::string buf_);
};

}
}
}

#endif /* _REMOVE_PLAIN_PREFIX_HPP_ */
#ifndef _UNSTEM_SHORT_WORD_HPP_
#define _UNSTEM_SHORT_WORD_HPP_

#include <stemmer/context/visitor/visitor-abstract.hpp>

namespace stemmer {
namespace context {
namespace visitor {

class UnstemShortWord : public VisitorAbstract
{
public:
	UnstemShortWord();
	~UnstemShortWord();
	
	void visit(stemmer::context::ContextAbstract& ctx_);

protected:
	bool isShortWord(std::string buf_);
};

}
}
}

#endif /* _UNSTEM_SHORT_WORD_HPP_ */
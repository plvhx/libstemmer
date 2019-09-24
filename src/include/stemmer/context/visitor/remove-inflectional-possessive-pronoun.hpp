#ifndef _REMOVE_INFLECTIONAL_POSSESSIVE_PRONOUN_HPP_
#define _REMOVE_INFLECTIONAL_POSSESSIVE_PRONOUN_HPP_

#include <string>
#include <stemmer/context/visitor/visitor-abstract.hpp>

namespace stemmer {
namespace context {
namespace visitor {

class RemoveInflectionalPossessivePronoun : public VisitorAbstract
{
public:
	RemoveInflectionalPossessivePronoun();
	~RemoveInflectionalPossessivePronoun();
	
	void visit(stemmer::context::ContextAbstract& ctx_);
	std::string remove(std::string buf_);
};

}
}
}

#endif /* _REMOVE_INFLECTIONAL_POSSESSIVE_PRONOUN_HPP_ */
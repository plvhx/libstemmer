#ifndef _REMOVE_INFLECTIONAL_PARTICLE_HPP_
#define _REMOVE_INFLECTIONAL_PARTICLE_HPP_

#include <string>
#include <stemmer/context/visitor/visitor-abstract.hpp>

namespace stemmer {
namespace context {
namespace visitor {

class RemoveInflectionalParticle : public VisitorAbstract
{
public:
	RemoveInflectionalParticle();
	~RemoveInflectionalParticle();
	
	void visit(stemmer::context::ContextAbstract& ctx_);
	std::string remove(std::string buf_);
};

}
}
}

#endif /* _REMOVE_INFLECTIONAL_PARTICLE_HPP_ */
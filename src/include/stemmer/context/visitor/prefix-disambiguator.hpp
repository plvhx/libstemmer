#ifndef _PREFIX_DISAMBIGUATOR_HPP_
#define _PREFIX_DISAMBIGUATOR_HPP_

#include <string>
#include <vector>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/context/visitor/visitor-abstract.hpp>

namespace stemmer {
namespace context {
namespace visitor {

class PrefixDisambiguator : public VisitorAbstract
{
public:
	PrefixDisambiguator(std::vector<stemmer::DisambiguatorAbstract *>& rda_, std::string rule_): da_(rda_), ruleName_(rule_) {}
	~PrefixDisambiguator() {}

	void visit(stemmer::context::ContextAbstract& ctx_);
	std::string getRuleName();

protected:
	std::vector<stemmer::DisambiguatorAbstract *>& da_;
	std::string ruleName_;
};

}
}
}

#endif /* _PREFIX_DISAMBIGUATOR_HPP_ */
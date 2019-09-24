#ifndef _VISITOR_PROVIDER_HPP_
#define _VISITOR_PROVIDER_HPP_

#include <vector>

#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator-rule-factory.hpp>
#include <stemmer/context/visitor/visitor-abstract.hpp>

namespace stemmer {
namespace context {
namespace visitor {

class VisitorProvider
{
public:
	VisitorProvider();
	~VisitorProvider();

	std::vector<VisitorAbstract *>& getVisitors();
	std::vector<VisitorAbstract *>& getSuffixVisitors();
	std::vector<VisitorAbstract *>& getPrefixVisitors();

protected:
	stemmer::DisambiguatorRuleFactory *fact_;
	std::vector<VisitorAbstract *> visitors_;
	std::vector<VisitorAbstract *> suffix_visitors_;
	std::vector<VisitorAbstract *> prefix_visitors_;

	void initVisitors();
	template<class T> void destroyVisitor(std::vector<T *>& ida_);
	void purgeExistingVisitors();
};

}
}
}

#endif /* _VISITOR_PROVIDER_HPP_ */
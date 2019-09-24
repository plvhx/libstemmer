#ifndef _RULE_30B_HPP_
#define _RULE_30B_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule30b : public stemmer::DisambiguatorAbstract
{
public:
	Rule30b();
	~Rule30b();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_30B_HPP_ */
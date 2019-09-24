#ifndef _RULE_13B_HPP_
#define _RULE_13B_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule13b : public stemmer::DisambiguatorAbstract
{
public:
	Rule13b();
	~Rule13b();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_13B_HPP_ */
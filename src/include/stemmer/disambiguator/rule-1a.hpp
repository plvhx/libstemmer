#ifndef _RULE_1A_HPP_
#define _RULE_1A_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule1a : public stemmer::DisambiguatorAbstract
{
public:
	Rule1a();
	~Rule1a();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_1A_HPP_ */
#ifndef _RULE_17C_HPP_
#define _RULE_17C_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule17c : public stemmer::DisambiguatorAbstract
{
public:
	Rule17c();
	~Rule17c();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_17C_HPP_ */
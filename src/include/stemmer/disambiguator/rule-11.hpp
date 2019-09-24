#ifndef _RULE_11_HPP_
#define _RULE_11_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule11 : public stemmer::DisambiguatorAbstract
{
public:
	Rule11();
	~Rule11();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_11_HPP_ */
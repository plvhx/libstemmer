#ifndef _RULE_14_HPP_
#define _RULE_14_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule14 : public stemmer::DisambiguatorAbstract
{
public:
	Rule14();
	~Rule14();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_14_HPP_ */
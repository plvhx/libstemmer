#ifndef _RULE_7_HPP_
#define _RULE_7_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule7 : public stemmer::DisambiguatorAbstract
{
public:
	Rule7();
	~Rule7();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_7_HPP_ */
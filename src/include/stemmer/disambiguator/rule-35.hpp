#ifndef _RULE_35_HPP_
#define _RULE_35_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule35 : public stemmer::DisambiguatorAbstract
{
public:
	Rule35();
	~Rule35();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_35_HPP_ */
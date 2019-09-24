#ifndef _RULE_15A_HPP_
#define _RULE_15A_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule15a : public stemmer::DisambiguatorAbstract
{
public:
	Rule15a();
	~Rule15a();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_15A_HPP_ */
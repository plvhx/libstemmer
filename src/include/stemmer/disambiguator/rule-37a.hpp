#ifndef _RULE_37A_HPP_
#define _RULE_37A_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule37a : public stemmer::DisambiguatorAbstract
{
public:
	Rule37a();
	~Rule37a();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_37A_HPP_ */
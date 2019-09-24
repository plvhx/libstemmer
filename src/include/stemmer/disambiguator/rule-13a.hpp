#ifndef _RULE_13A_HPP_
#define _RULE_13A_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule13a : public stemmer::DisambiguatorAbstract
{
public:
	Rule13a();
	~Rule13a();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_13A_HPP_ */
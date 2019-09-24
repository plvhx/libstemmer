#ifndef _RULE_41_HPP_
#define _RULE_41_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule41 : public stemmer::DisambiguatorAbstract
{
public:
	Rule41();
	~Rule41();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_41_HPP_ */
#ifndef _RULE_27_HPP_
#define _RULE_27_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule27 : public stemmer::DisambiguatorAbstract
{
public:
	Rule27();
	~Rule27();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_27_HPP_ */
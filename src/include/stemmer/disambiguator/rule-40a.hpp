#ifndef _RULE_40A_HPP_
#define _RULE_40A_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule40a : public stemmer::DisambiguatorAbstract
{
public:
	Rule40a();
	~Rule40a();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_40A_HPP_ */
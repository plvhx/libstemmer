#ifndef _RULE_25_HPP_
#define _RULE_25_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule25 : public stemmer::DisambiguatorAbstract
{
public:
	Rule25();
	~Rule25();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_25_HPP_ */
#ifndef _RULE_31B_HPP_
#define _RULE_31B_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule31b : public stemmer::DisambiguatorAbstract
{
public:
	Rule31b();
	~Rule31b();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_31B_HPP_ */
#ifndef _RULE_40B_HPP_
#define _RULE_40B_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule40b : public stemmer::DisambiguatorAbstract
{
public:
	Rule40b();
	~Rule40b();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_40B_HPP_ */
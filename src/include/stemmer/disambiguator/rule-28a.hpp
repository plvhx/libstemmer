#ifndef _RULE_28A_HPP_
#define _RULE_28A_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule28a : public stemmer::DisambiguatorAbstract
{
public:
	Rule28a();
	~Rule28a();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_28A_HPP_ */
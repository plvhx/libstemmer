#ifndef _RULE_28B_HPP_
#define _RULE_28B_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule28b : public stemmer::DisambiguatorAbstract
{
public:
	Rule28b();
	~Rule28b();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_28B_HPP_ */
#ifndef _RULE_26B_HPP_
#define _RULE_26B_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule26b : public stemmer::DisambiguatorAbstract
{
public:
	Rule26b();
	~Rule26b();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_26B_HPP_ */
#ifndef _RULE_26A_HPP_
#define _RULE_26A_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule26a : public stemmer::DisambiguatorAbstract
{
public:
	Rule26a();
	~Rule26a();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_26A_HPP_ */
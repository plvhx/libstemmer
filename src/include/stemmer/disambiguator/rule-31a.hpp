#ifndef _RULE_31A_HPP_
#define _RULE_31A_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule31a : public stemmer::DisambiguatorAbstract
{
public:
	Rule31a();
	~Rule31a();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_31A_HPP_ */
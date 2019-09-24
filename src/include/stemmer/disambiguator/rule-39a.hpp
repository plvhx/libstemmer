#ifndef _RULE_39A_HPP_
#define _RULE_39A_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule39a : public stemmer::DisambiguatorAbstract
{
public:
	Rule39a();
	~Rule39a();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_39A_HPP_ */
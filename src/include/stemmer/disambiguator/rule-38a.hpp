#ifndef _RULE_38A_HPP_
#define _RULE_38A_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule38a : public stemmer::DisambiguatorAbstract
{
public:
	Rule38a();
	~Rule38a();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_38A_HPP_ */
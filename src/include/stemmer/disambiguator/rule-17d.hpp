#ifndef _RULE_17D_HPP_
#define _RULE_17D_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule17d : public stemmer::DisambiguatorAbstract
{
public:
	Rule17d();
	~Rule17d();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_17D_HPP_ */
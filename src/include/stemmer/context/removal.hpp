#ifndef _REMOVAL_HPP_
#define _REMOVAL_HPP_

#include <string>
#include <stemmer/context/visitor/visitor-abstract.hpp>
#include <stemmer/context/removal-abstract.hpp>

namespace stemmer {
namespace context {

class Removal : public RemovalAbstract
{
public:
	Removal(std::string sub_, std::string res_, std::string rp_, std::string atype_): subject_(sub_), result_(res_), removed_part_(rp_), affix_type_(atype_)
	{
	}

	~Removal()
	{
	}

	std::string getSubject();
	std::string getResult();
	std::string getRemovedPart();
	std::string getAffixType();

protected:
	std::string subject_;
	std::string result_;
	std::string removed_part_;
	std::string affix_type_;
};

}
}

#endif /* _REMOVAL_HPP_ */
#include <string>
#include <vector>
#include <stemmer/context/removal.hpp>

using namespace std;
using namespace stemmer::context;
using namespace stemmer::context::visitor;

std::string Removal::getSubject()
{
	return subject_;
}

std::string Removal::getResult()
{
	return result_;
}

std::string Removal::getRemovedPart()
{
	return removed_part_;
}

std::string Removal::getAffixType()
{
	return affix_type_;
}
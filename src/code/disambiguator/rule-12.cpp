#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-12.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule12::Rule12()
{
}

Rule12::~Rule12()
{
}

bool Rule12::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^mempe(.*)$");
	string m0;

	if (!reg_.FullMatch(buf_, &m0))
		return false;

	rbuf_ = string("pe") + m0;

	return true;
}
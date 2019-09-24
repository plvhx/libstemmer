#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-1b.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule1b::Rule1b()
{
}

Rule1b::~Rule1b()
{
}

bool Rule1b::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^ber([aiueo].*)$");
	string m0;

	if (!reg_.FullMatch(buf_, &m0))
		return false;

	rbuf_ = string("r") + m0;

	return true;
}
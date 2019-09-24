#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-1a.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule1a::Rule1a()
{
}

Rule1a::~Rule1a()
{
}

bool Rule1a::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^ber([aiueo].*)$");
	string m0;

	if (!reg_.FullMatch(buf_, &m0))
		return false;

	rbuf_ = m0;

	return true;
}
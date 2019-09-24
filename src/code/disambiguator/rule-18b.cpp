#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-18b.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule18b::Rule18b()
{
}

Rule18b::~Rule18b()
{
}

bool Rule18b::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^meny([aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = string("s") + m0 + m1;

	return true;
}
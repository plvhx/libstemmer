#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-17b.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule17b::Rule17b()
{
}

Rule17b::~Rule17b()
{
}

bool Rule17b::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^meng([aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = string("k") + m0 + m1;

	return true;
}
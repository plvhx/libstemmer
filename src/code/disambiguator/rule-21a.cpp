#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-21a.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule21a::Rule21a()
{
}

Rule21a::~Rule21a()
{
}

bool Rule21a::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^per([aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = m0 + m1;

	return true;
}
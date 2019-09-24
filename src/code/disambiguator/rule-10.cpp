#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-10.hpp>

using namespace std;
using namespace pcrecpp;
using namespace stemmer::disambiguator;

Rule10::Rule10()
{
}

Rule10::~Rule10()
{
}

bool Rule10::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^me([lrwy])([aiueo])(.*)$");
	string m0, m1, m2;

	if (!reg_.FullMatch(buf_, &m0, &m1, &m2))
		return false;

	rbuf_ = m0 + m1 + m2;

	return true;
}
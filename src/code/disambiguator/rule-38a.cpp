#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-38a.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule38a::Rule38a()
{
}

Rule38a::~Rule38a()
{
}

bool Rule38a::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^([bcdfghjklmnpqrstvwxyz])(el[aiueo])(.*)$");
	string m0, m1, m2;

	if (!reg_.FullMatch(buf_, &m0, &m1, &m2))
		return false;

	rbuf_ = m0 + m1 + m2;

	return true;
}
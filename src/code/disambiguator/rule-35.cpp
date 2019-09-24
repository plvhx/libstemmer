#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-35.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule35::Rule35()
{
}

Rule35::~Rule35()
{
}

bool Rule35::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^ter([bcdfghjkpqstvxz])(er[bcdfghjklmnpqrstvwxyz])(.*)$");
	string m0, m1, m2;

	if (!reg_.FullMatch(buf_, &m0, &m1, &m2))
		return false;

	rbuf_ = m0 + m1 + m2;

	return true;
}
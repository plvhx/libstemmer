#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-19.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule19::Rule19()
{
}

Rule19::~Rule19()
{
}

bool Rule19::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^memp([abcdfghijklmopqrstuvwxyz])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = string("p") + m0 + m1;

	return true;
}
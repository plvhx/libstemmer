#include <string>
#include <stemmer/context/visitor/unstem-short-word.hpp>

using namespace std;
using namespace stemmer::context;
using namespace stemmer::context::visitor;

UnstemShortWord::UnstemShortWord()
{
}

UnstemShortWord::~UnstemShortWord()
{
}

void UnstemShortWord::visit(ContextAbstract& ctx_)
{
	if (isShortWord(ctx_.getCurrentWord()))
		ctx_.stopProcess();
}

bool UnstemShortWord::isShortWord(string buf_)
{
	return (buf_.size() <= 3);
}
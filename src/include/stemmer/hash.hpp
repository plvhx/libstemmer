#ifndef _HASH_HPP_
#define _HASH_HPP_

#include <string>
#include <cstddef>
#include <cstdint>

#ifndef ROL_32
# define ROL_32(x, i)	(((x) << (i)) | ((x) >> (32 - (i))))
#endif

namespace stemmer {

class Hash
{
public:
	Hash();
	~Hash();

	uint32_t generate(std::string buf_, uint32_t seed);
};

}

#endif /* _HASH_HPP_ */
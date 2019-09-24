#include <cstddef>
#include <string>
#include <stemmer/hash.hpp>

using namespace std;
using namespace stemmer;

Hash::Hash()
{
}

Hash::~Hash()
{
}

uint32_t Hash::generate(string buf_, uint32_t seed)
{
	uint32_t hash = seed;
	const int32_t qlen = (int32_t)(buf_.size()) >> 2;
	uint32_t k;
	const uint8_t *cbuf = (const uint8_t *)(buf_.data());
	const uint32_t vector1 = 0xcc9e2d51;
	const uint32_t vector2 = 0x1b873593;

	const uint32_t *mbuf = (const uint32_t *)(cbuf + (qlen * 4));

	for (int i = -qlen; i; i++) {
		k = mbuf[i];
		k *= vector1;
		k = ROL_32(k, 15);
		k *= vector2;
		hash ^= k;
		hash = ROL_32(hash, 13);
		hash = (hash * 5) + 0xe6546b64;
	}

	const uint8_t *rem = (const uint8_t *)(cbuf + (qlen * 4));

	k = 0;
	
	switch (buf_.size() & 3) {
	case 3: k ^= (uint8_t)rem[2] << 16;
	case 2: k ^= (uint8_t)rem[1] <<  8;
	case 1: k ^= (uint8_t)rem[0] <<  0;
		k *= vector1; k = ROL_32(k, 15); k *= vector2; hash ^= k;
	}

	hash ^= (int32_t)(buf_.size());
	hash ^= (hash >> 16);
	hash *= 0x85ebca6b;
	hash ^= (hash >> 13);
	hash *= 0xc2b2ae35;
	hash ^= (hash >> 16);

	return hash;
}
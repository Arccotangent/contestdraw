/*
This file is part of ContestDraw.

ContestDraw is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

ContestDraw is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ContestDraw.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "seed-hasher.h"
#include <cstring>
#include <openssl/sha.h>
using namespace std;

string SeedHasher::hashSeed(string seed, string salt) {
	unsigned char digest[SHA512_DIGEST_LENGTH];
	auto *toDigest = (char*) malloc(salt.length());

	toDigest = (char*) realloc(toDigest, seed.length());

	strcat(toDigest, seed.c_str());

	SHA512((unsigned char*) toDigest, strlen(toDigest), (unsigned char*) &digest);

	char digestHex[SHA512_DIGEST_LENGTH * 2 + 1];

	for (int i = 0; i < SHA512_DIGEST_LENGTH; i++) {
		sprintf(&digestHex[i * 2], "%02x", (unsigned int) digest[i]);
	}

	return string(digestHex);
}

/*
ContestDraw - User-verifiable, provably fair contest drawings
Copyright (C) 2018 Arccotangent

ContestDraw is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see http://www.gnu.org/licenses.
*/

#include "version.h"
#include "crypto/salt.h"
#include "crypto/seed-hasher.h"
#include <iostream>
#include <cstring>
#include <random>

using namespace std;

int main(int argc, char *argv[]) {
	cout << "ContestDraw by Arccotangent" << endl;
	cout << "Version: " << VERSION << endl;

	if (argc < 2) {
		cout << "Usage: contestdraw <operation> [arguments]" << endl;
		cout << endl;
		cout << "Operations:" << endl;
		cout << "genseed - Generate a new random seed along with a random salt for security and a hash for later user verification." << endl;
		cout << "verifyseed <seed> <salt> <hash> - Verify a seed's authenticity." << endl;
		cout << "draw <seed> <min> <max> - Perform or verify a drawing with given seed, minimum, and maximum values." << endl;

		return 1;
	}

	if (strcmp(argv[1], "genseed") == 0) {
		random_device r;
		string seed = to_string(r());
		string salt = Salt::generateRandomSalt();

		string sha512hash = SeedHasher::hashSeed(seed, salt);
		cout << "Seed (keep private until after drawing): " << seed << endl;
		cout << "Salt (keep private until after drawing): " << salt << endl;
		cout << "Hash (make public, users can verify later with this hash): " << sha512hash << endl;


	} else if (strcmp(argv[1], "verifyseed") == 0) {
		if (argc < 5) {
			cout << "Invalid amount of arguments. Please review your argument count." << endl;
			cout << "verifyseed <seed> <salt> <hash>" << endl;
			return 1;
		}

		string seed = argv[2];
		string salt = argv[3];
		string hash = argv[4];

		string hashVerify = SeedHasher::hashSeed(seed, salt);

		cout << (hash == hashVerify ? "Hash matches. This seed is authentic." : "Hash does NOT match. This seed is NOT authentic!") << endl;
	} else if (strcmp(argv[1], "draw") == 0) {
		if (argc < 5) {
			cout << "Invalid amount of arguments. Please review your argument count." << endl;
			cout << "draw <seed> <min> <max>" << endl;
			return 1;
		}

		auto seed = (unsigned int) strtol(argv[2], nullptr, 10);

		long min, max;
		min = strtol(argv[3], nullptr, 10);
		max = strtol(argv[4], nullptr, 10);

		srand(seed);

		long result = rand() % (max - min + 1) + min;

		cout << "Result: " << result << endl;
	} else {
		cout << "Invalid command." << endl;
		return 1;
	}

	return 0;
}

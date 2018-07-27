# ContestDraw

ContestDraw is a simple tool that can be used to produce provably fair drawings for contests using the classic scheme of hashing the server seed with a salt.

## Compilation

### Dependencies

* OpenSSL 1.1.0
* CMake 3.10 or later

Clone the Git repository and navigate to it in the command line. Optionally, create a build folder inside of your copy of the repository.

Run CMake on the repository's root to generate build files.

After build files have been generated, run `make` (GNU Make) in the folder containing the build files. This will produce an executable named `contestdraw` or `contestdraw.exe` depending on your platform.

## Usage

Problem: A person wishes to start a contest or giveaway with a provably fair random drawing.

Solution: The contest holder uses ContestDraw to randomly generate a seed, salt, and hash. The hash is made public, however the seed and salt are kept private and saved securely.

The contest's participants enter, each possessing a unique number (preferably sequential, eg. post number).

When the contest ends, the contest holder uses ContestDraw to draw a pseudo-random number using the seed generated before. Once the winner has been announced, the seed and salt are made public.

Any users wishing to verify the authenticity of the draw can use ContestDraw to verify the seed, salt, and hash posted by the contest holder. Then, users can use the verified seed to recreate the draw in the same manner that the contest holder did.

The below instructions detail how to use ContestDraw. All instructions below assume that you are in the same folder as the executable.

### Generating a Seed

This command generates a random seed and a random salt. Then, it passes the seed and salt through the SHA-512 hashing algorithm. All 3 values are then printed to the console. 

Windows: `contestdraw genseed`
Linux: `./contestdraw genseed`

Sample (Linux):
```
$ ./contestdraw genseed
ContestDraw by Arccotangent
Version: 0.1
Seed (keep private until after drawing): 3371157871
Salt (keep private until after drawing): eAxgH10G20Z3Ks9H4O4GvdE74eO9ttHlBpCSOw1Nxh0pLYkT4BfqcBAr44YS4dYs
Hash (make public, users can verify later with this hash): 8079be565cc85a9ea0a2dcecccc4c83daf23c4a150eea13ab1d33dd915123e060e340fb9cfffce590abc15d4be83f7bc11e4e1a4b9d83fabb0cebd8ae2921047
```

### Verifying a Seed's Authenticity

This command takes 3 arguments (the seed, salt, and hash), and hashes the seed and salt arguments. It will then compare the generated hash with the user given hash and produce console output accordingly.

Windows: `contestdraw verifyseed <seed> <salt> <hash>`

Linux: `./contestdraw verifyseed <seed> <salt> <hash>`

Sample (Linux, matching hash):
```
$ ./contestdraw verifyseed 3371157871 eAxgH10G20Z3Ks9H4O4GvdE74eO9ttHlBpCSOw1Nxh0pLYkT4BfqcBAr44YS4dYs 8079be565cc85a9ea0a2dcecccc4c83daf23c4a150eea13ab1d33dd915123e060e340fb9cfffce590abc15d4be83f7bc11e4e1a4b9d83fabb0cebd8ae2921047
ContestDraw by Arccotangent
Version: 0.1
Hash matches. This seed is authentic.
```

Sample (Linux, non-matching hash):
```
$ ./contestdraw verifyseed 3371157872 eAxgH10G20Z3Ks9H4O4GvdE74eO9ttHlBpCSOw1Nxh0pLYkT4BfqcBAr44YS4dYs 8079be565cc85a9ea0a2dcecccc4c83daf23c4a150eea13ab1d33dd915123e060e340fb9cfffce590abc15d4be83f7bc11e4e1a4b9d83fabb0cebd8ae2921047
ContestDraw by Arccotangent
Version: 0.1
Hash does NOT match. This seed is NOT authentic!
```

Notice how in the second sample, the seed is incremented by 1. This causes the hash function to produce a different hash, causing the verification to fail. This also happens if the salt is changed in any way.

### Drawing

This command will draw a single number between two values given a seed.

Windows: `contestdraw draw <seed> <min> <max>`

Linux: `./contestdraw draw <seed> <min> <max>`

Sample (Linux, drawing a number between 1 and 100 using above sample seed):

```
$ ./contestdraw draw 3371157871 1 100
ContestDraw by Arccotangent
Version: 0.1
Result: 92
```

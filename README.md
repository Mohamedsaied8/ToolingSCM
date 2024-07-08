# Configuration

Please modify .bazelrc as it's needed
The original .bazelrc is made to compile with g++ 9 that doesn't support C++ concepts but only the earlier Concepts Technical Specification (TS)
That's also the reason why one file is excluded (moved into the "concepts" directory)

# Example of usage:

bazel test --test_output=all //type-traits

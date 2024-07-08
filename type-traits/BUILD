cc_library(
  name = "type-traits-lib",
  hdrs = glob(["*.h"]),
)


cc_test(
  name = "type-traits",
  size = "small",
  srcs = glob(["*.cpp"]),
  deps = ["@gtest//:gtest_main", ":type-traits-lib"],
)

#!/bin/bash
cd build
./CalculatorTests
lcov --directory . --rc lcov_branch_coverage=1 --capture --output-file coverage.info
lcov --rc lcov_branch_coverage=1 --remove coverage.info '/usr/include/*' '/workspaces/Example-Project/build/_deps/googletest-src/*' '/workspaces/Example-Project/third_party/*' '/workspaces/Example-Project/test/*' -o coverage_filtered.info
genhtml --legend --title "commit SHA1" --rc lcov_branch_coverage=1 -o report coverage_filtered.info

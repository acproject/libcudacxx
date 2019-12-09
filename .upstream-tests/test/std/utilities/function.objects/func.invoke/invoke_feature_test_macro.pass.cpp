//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <cuda/std/functional>

// template <class F, class ...Args>
// result_of_t<F&&(Args&&...)> invoke(F&&, Args&&...);

#include <cuda/std/functional>
#include <cuda/std/cassert>

#include "test_macros.h"

#if TEST_STD_VER <= 14
# ifdef __cpp_lib_invoke
#   error Feature test macro should be defined
# endif
#else
# ifndef __cpp_lib_invoke
#   error Feature test macro not defined
# endif
# if __cpp_lib_invoke != 201411
#   error __cpp_lib_invoke has the wrong value
# endif
#endif

__host__ __device__
int foo(int) { return 42; }

int main(int, char**) {
#if defined(__cpp_lib_invoke)
  assert(cuda::std::invoke(foo, 101) == 42);
#endif

  return 0;
}
/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2022 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/platform.h>

// Include the implementation of the default main().
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

// ----------------------------------------------------------------------------

// Simple examples of functions to be tested.
static int
compute_one (void)
{
  return 1;
}

static const char*
compute_aaa (void)
{
  return "aaa";
}

static bool
compute_condition (void)
{
  return true;
}

#if defined(__EXCEPTIONS)

static void
exercise_throw (bool mustThrow)
{
  if (mustThrow)
    {
      throw "kaboom";
    }
}

#endif // defined(__EXCEPTIONS)

// ----------------------------------------------------------------------------

TEST_CASE ("Check various conditions")
{
  CHECK (compute_one () == 1);
  CHECK (strcmp (compute_aaa (), "aaa") == 0);
  CHECK (compute_condition ());
}

#if defined(__EXCEPTIONS)

TEST_CASE ("Check exceptions")
{
  CHECK_THROWS (exercise_throw (true));
  CHECK_NOTHROW (exercise_throw (false));
}

#endif // defined(__EXCEPTIONS)

// ----------------------------------------------------------------------------

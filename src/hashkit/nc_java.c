/*
 * twemproxy - A fast and lightweight proxy for memcached protocol.
 * Copyright (C) 2011 Twitter, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <nc_core.h>

static int32_t HASH_INIT = 0;
static int32_t HASH_PRIME = 31;

uint32_t
hash_java(const char *key, size_t key_length)
{
  int32_t hash = HASH_INIT;
  size_t x = 0;

  for (x = 0; x < key_length; x++) {
    hash *= HASH_PRIME;
    hash += (int32_t)key[x];
  }

  return hash > 0 ? (uint32_t) hash : (uint32_t) (hash * -1L);
}

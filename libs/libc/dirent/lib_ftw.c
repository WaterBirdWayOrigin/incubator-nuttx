/****************************************************************************
 * libs/libc/dirent/lib_ftw.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <ftw.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

int ftw(FAR const char *path, ftw_cb_t fn, int fdlimit)
{
  /* The following cast assumes that calling a function with one
   * argument more than it needs behaves as expected. This is
   * actually undefined, but works on all real-world machines.
   */

  return nftw(path, (nftw_cb_t)fn, fdlimit, FTW_PHYS);
}
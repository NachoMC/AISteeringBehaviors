#ifndef __SLIST_H
#define __SLIST_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2009, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at http://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 * $Id: slist.h,v 1.1 2009-03-09 12:21:47 bagder Exp $
 ***************************************************************************/

/*
 * Curl_slist_duplicate() duplicates a linked list. It always returns the
 * address of the first record of the cloned list or NULL in case of an
 * error (or if the input list was NULL).
 */
struct curl_slist *Curl_slist_duplicate(struct curl_slist *inlist);

#endif /* __SLIST_H */

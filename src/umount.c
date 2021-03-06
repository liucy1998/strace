/*
 * Copyright (c) 2014-2021 The strace developers.
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include "defs.h"
#include "xlat/umount_flags.h"

SYS_FUNC(umount2)
{
	/* target */
	printpath(tcp, tcp->u_arg[0]);
	tprint_arg_next();

	/* flags */
	printflags(umount_flags, tcp->u_arg[1], "MNT_???");

	return RVAL_DECODED;
}

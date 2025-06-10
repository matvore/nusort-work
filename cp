#!/bin/sh

export LC_ALL=C

( make -j 8 2>&1 ; echo result: $? >&2
) | tr '\t' '@' | sed '
	/^>[ @]*cp /!d; s//cp /
' | /bin/sh -x

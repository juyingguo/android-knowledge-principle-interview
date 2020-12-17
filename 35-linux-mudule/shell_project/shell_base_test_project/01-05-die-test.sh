#!/bin/sh
:<<!
if [ "$PS1" ]; then echo test is ok;
fi
!
cross_deal="cross_deal_set"

if test -n $cross_deal
 then test -n $cross_deal && test -n $cross_deal || 
	die "must specify B and C when use cross deal."
	echo "must specify B and C"
fi
echo $cross_deal
echo "finish."


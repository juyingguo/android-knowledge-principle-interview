#!/bin/sh
:<<!
if [ "$PS1" ]; then echo test is ok;
fi
!
if [ "$PS1" ];
 then echo "my test is ok"
fi


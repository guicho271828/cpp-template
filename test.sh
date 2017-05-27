#!/bin/bash

set -eu
export LANG=C

result=false
handle (){
    if $result; then
        echo success!
    else
        echo fail!
    fi
}

trap handle EXIT


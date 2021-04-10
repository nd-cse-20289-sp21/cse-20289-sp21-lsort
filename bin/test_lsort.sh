#!/bin/bash

SCRIPT=bin/lsort
WORKSPACE=/tmp/$(basename $SCRIPT).$(id -u)
FAILURES=0

error() {
    echo "$@"
    echo
    [ -r $WORKSPACE/test ] && cat $WORKSPACE/test
    echo
    FAILURES=$((FAILURES + 1))
}

cleanup() {
    STATUS=${1:-$FAILURES}
    rm -fr $WORKSPACE
    exit $STATUS
}

mkdir $WORKSPACE

trap "cleanup" EXIT
trap "cleanup 1" INT TERM

export LC_ALL=C

echo "Testing $SCRIPT ..."

printf " %-40s ... " "Usage"
./$SCRIPT -h 2>&1 | grep -i usage 2>&1 > /dev/null
if [ $? -ne 0 ]; then
    error "Failed Usage Test"
else
    echo "Success"
fi

printf " %-40s ... " "lsort    on /etc/passwd"
cat /etc/passwd | ./$SCRIPT | diff -y - <(cat /etc/passwd | sort) > $WORKSPACE/test
if [ $? -ne 0 ]; then
    error "Failure"
else
    echo "Success"
fi

printf " %-40s ... " "lsort -r on /etc/passwd"
cat /etc/passwd | ./$SCRIPT -r | diff -y - <(cat /etc/passwd | sort -r) > $WORKSPACE/test
if [ $? -ne 0 ]; then
    error "Failure"
else
    echo "Success"
fi

printf " %-40s ... " "lsort    on /etc/hosts"
cat /etc/hosts | ./$SCRIPT | diff -y - <(cat /etc/hosts| sort -) > $WORKSPACE/test
if [ $? -ne 0 ]; then
    error "Failure"
else
    echo "Success"
fi

printf " %-40s ... " "lsort -r on /etc/hosts"
cat /etc/hosts | ./$SCRIPT -r | diff -y - <(cat /etc/hosts| sort -r -) > $WORKSPACE/test
if [ $? -ne 0 ]; then
    error "Failure"
else
    echo "Success"
fi

printf " %-40s ... " "lsort    on seq 1000 | shuf"
seq 1000 | shuf | ./$SCRIPT | diff -y - <(seq 1000 | shuf | sort -) > $WORKSPACE/test
if [ $? -ne 0 ]; then
    error "Failure"
else
    echo "Success"
fi

printf " %-40s ... " "lsort -r on seq 1000 | shuf"
seq 1000 | shuf | ./$SCRIPT -r | diff -y - <(seq 1000 | shuf | sort -r -) > $WORKSPACE/test
if [ $? -ne 0 ]; then
    error "Failure"
else
    echo "Success"
fi

TESTS=$(($(grep -c Success $0) - 1))
echo
echo "   Score $(echo "scale=2; ($TESTS - $FAILURES) / $TESTS.0 * 4.0" | bc | awk '{printf "%0.2f\n", $1}')"
echo

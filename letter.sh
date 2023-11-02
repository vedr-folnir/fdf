#!/bin/bash
if [ $# -eq 0 ]; then
  echo "Aucun argument spécifié."
  exit 1
fi
cat /dev/null > alpha/temp
for arg in "$@"; do
  foo=$arg
  for (( i=0; i<${#foo}; i++ )); do
    cat alpha/"${foo:$i:1}" >> alpha/temp
  done
  if [ "$arg" != "${@:$#}" ];then
    cat alpha/0 >> alpha/temp
  fi
done

./fdf alpha/temp
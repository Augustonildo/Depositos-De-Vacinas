EXEC=$1
TMP_OUT=$2

for i in {0..3..1}; do
  testname=$(printf "ct0%01d" $i)
  $EXEC tarefa1 tests/$testname.txt > $TMP_OUT
  if ! diff -qwB tests/out_$testname.txt $TMP_OUT &>/dev/null; then
    echo "Test $testname failed"
  else
    echo "Test $testname passed"
  fi
done
rm $TMP_OUT

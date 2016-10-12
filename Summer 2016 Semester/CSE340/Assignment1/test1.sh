#!/bin/bash

let count=0;
for f in $(ls ./tests/*.txt); do 
	#echo "Running $f"
	./a.out <$f > ./tests/`basename $f .txt`.output; 
done;

for f in $(ls ./tests/*.output); do
	diff -Bw $f  ./tests/`basename $f .output`.txt.expected > ./tests/`basename $f .output`.diff;
done

for f in $(ls tests/*.diff); do
	echo "========================================================";
	echo "FILE:" `basename $f .output`;
	echo "========================================================";
	if [ -s $f ]; then
		cat ./tests/`basename $f .diff`.txt;
		echo "--------------------------------------------------------";
		cat $f
	else
		count=$((count+1));
		echo "NO ERRORS HERE!";
	fi
done

echo $count;

#rm tests/*.output
rm tests/*.diff


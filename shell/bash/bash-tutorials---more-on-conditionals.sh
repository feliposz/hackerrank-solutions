read a 
read b
read c
if [ $a -eq $b -a $a -eq $c ]; then
    echo EQUILATERAL
elif [ $a -eq $b -o $a -eq $c -o $b -eq $c ]; then
    echo ISOSCELES
else
    echo SCALENE
fi



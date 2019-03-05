read COUNT
readarray ARR
ADD=$( echo ${ARR[@]} | tr " " "+" )
printf "%.3f" $(echo "( $ADD ) / ${#ARR[@]}.000" | bc -l)


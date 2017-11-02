set xrange[0:5]

log2(x)=log(x)/log(2)

plot log2(x)
replot x
replot x*log2(x)
replot x*x

pause -1

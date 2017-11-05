set xrange[0:50]

log2(x)=log(x)/log(2)

plot log2(x)
replot x
replot 64 * x * log2(x)
replot 8  * x * x

pause -1

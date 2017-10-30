set xrange[0:10]

plot x*x

log2(x)=log(x)/log(2)

replot log2(x)
replot x*log2(x)

pause -1

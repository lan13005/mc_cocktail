root -l -b -q 'stackMC.C()'
montage stackHists/none-stack* -geometry +0+0 -mode Concatenate -tile 3x2 stackHists/montage-none.jpg
montage stackHists/none-summed* -geometry +0+0 -mode Concatenate -tile 3x2 stackHists/montage-none-sumVsSig.jpg

montage stackHists/as-stack* -geometry +0+0 -mode Concatenate -tile 3x2 stackHists/montage-as.jpg
montage stackHists/as-summed* -geometry +0+0 -mode Concatenate -tile 3x2 stackHists/montage-as-sumVsSig.jpg

montage stackHists/asbs-stack* -geometry +0+0 -mode Concatenate -tile 3x2 stackHists/montage-asbs.jpg
montage stackHists/asbs-summed* -geometry +0+0 -mode Concatenate -tile 3x2 stackHists/montage-asbs-sumVsSig.jpg

montage stackHists/asq-stack* -geometry +0+0 -mode Concatenate -tile 3x2 stackHists/montage-asq.jpg
montage stackHists/asq-summed* -geometry +0+0 -mode Concatenate -tile 3x2 stackHists/montage-asq-sumVsSig.jpg

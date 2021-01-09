# conv
Convert decimal, hexidecimal, and binary numbers

## usage

`conv [-d] [-x] [-b] [-h] <number>`

#### flags
```
-d	decimal: convert dec to bin and hex
-x	hexidecimal: convert hex to dec and bin
-b	binary: convert bin to dec and hex
-h	show this help message and exit
```

## installation

```
git clone

cd conv

make install
```

## test
Testing is done using the [minunit](https://github.com/siu/minunit) testing framework for C. However, by default, minunit displays results without colors, making it a bit hard to parse with lots of results. In the [minunit.h](https://github.com/breakthatbass/conv/blob/main/tests/minunit/minunit.h) here in the [`tests`](https://github.com/breakthatbass/conv/tree/main/tests) directory, I have added colors to the output.  
<br>
run all tests with: `sh run_tests.sh`

## TODO
1. add hex to decimal capability
2. add decimal to hex capability
3. add tests
4. needs lots of error checking
5. add capability for negative numbers
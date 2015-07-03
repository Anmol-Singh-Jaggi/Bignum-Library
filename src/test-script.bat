g++ -O2 test-case-generator.cpp -o test-case-generator
test-case-generator > test-cases

g++ -O2 bignum.cpp -o bignum
bignum < test-cases > cpp-output

python bignum-python.py < test-cases > python-output
fc cpp-output python-output

pause
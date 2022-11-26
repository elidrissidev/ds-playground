# data-structures-impl

My playground repository where I'm implementing data-structures using C!

## Running tests

Each data structure contains tests under a `*_test.c` file, to run it simply compile it with source file.

For example, to run tests for the array data structure in a unix environment:

```sh
$ gcc -g array/array.c array/array_test.c -o array/array_test
```

Optionally run the compiled binary using [valgrind](https://valgrind.org/docs/manual/quick-start.html) for memory leak checks:

```sh
$ valgrind --leak-check=full array/array_test
```

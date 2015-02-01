========================================================================
                                PICOZIP
========================================================================

A small Huffman Encoding exercise for my application to The Guildhall.

It takes in a source file to compress and will output it as a .pico file.
It can also read in the .pico file and recreate the original file.

The program was written in C++, but for fun I decided to create a GUI using
managed C++/CX and Winforms. Unfortunately, the GUI isn't very robust (I know
nothing of winforms), but it was a lot of fun to make regardless.

The underlying C++ program that does the actual work utilizes a Binary Tree I
built from scratch to construct the Huffman Encoding tree. I also used a
serializer that I had written earlier (for the undergraduate game design class
HGAM) to write out each of the bytes in an orderly manner. I wrote the encoding
algorithm using the high-level instructions given in the assignment, and made
sure that the code could read a file, compress it, read the compressed file, and
uncompress it to recreate the same exact file.

Once I had the program working, I decided to make a GUI for the encoder using
Visual C++/CX and Winforms. Since VS 2013 dropped support for C++ winforms, I
had to use an older laptop with VS 2010 to create the project, then upload it
to github so that VS 2013 could use it. This created a mess of the repo, and
the code is in two places. The outer project, Huffman Encoding, is the C++
backend of the project. Inside of it is PicoZip, the project that houses the
GUI end, as well as a copy of the C++ code so that it could stand alone.

Creating the GUI was relatively straightforward, but had its own challenges.
I had to use some multi-threading to implement a progress bar, and I also
learned a lot about Marshalling and the interop boundary in order to call the
C++ code I had written from the Managed GUI.

All in all, I had fun making this, and I hope you enjoy it!

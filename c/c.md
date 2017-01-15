<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#sec-1">1. IO</a></li>
<li><a href="#sec-2">2. Line-Oriented Input</a></li>
<li><a href="#sec-3">3. The things I still have to learn about C</a></li>
<li><a href="#sec-4">4. GDB</a>
<ul>
<li><a href="#sec-4-1">4.1. Cheat sheet</a>
<ul>
<li><a href="#sec-4-1-1">4.1.1. Breakpoints</a></li>
</ul>
</li>
</ul>
</li>
</ul>
</div>
</div>

# IO<a id="sec-1" name="sec-1"></a>

putc is usually the best function to use for writing a single
character. 
putchar 
fputs
puts writes out to stdout, adds newline. o
puts is the most convenient function for writing simple messages. 

Character input

# Line-Oriented Input<a id="sec-2" name="sec-2"></a>

A nonstandard *getline* function makes it easy to read lines
reliably. 

Another Gnu extension getdelim generalizes getline, it reads a
delimited record defined as everything through the next occurence of
a specified delimiter character. 

    size_t getline(**lineptr, size_t *n, FILE *stream)

This function reads an entire line from *stream*, storing the text
(including a newline and a terminating null character in a buffer
and storing the buffer address in \*lineptr. 

Before calling \`getline', you should place in \`\*LINEPTR' the
address of a buffer \`\*N' bytes long, allocated with \`malloc'.  If
this buffer is long enough to hold the line, \`getline' stores the
line in this buffer.  Otherwise, \`getline' makes the buffer bigger
using \`realloc', storing the new buffer address back in \`\*LINEPTR'
and the increased size back in \`\*N'.  \*Note Unconstrained
Allocation::.

# The things I still have to learn about C<a id="sec-3" name="sec-3"></a>

-   function pointers. I know how they work, I know how to use them. I
    just have to - use them.
    return<sub>type</sub> (\*var<sub>name</sub>) (param<sub>types</sub>)

-   variadic functions.

# GDB<a id="sec-4" name="sec-4"></a>

## Cheat sheet<a id="sec-4-1" name="sec-4-1"></a>

### Breakpoints<a id="sec-4-1-1" name="sec-4-1-1"></a>

\`break some<sub>function\`</sub>
\`break some<sub>file</sub>.c:120\`
\`break 12\`

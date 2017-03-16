# Analysis-of-Sorting-Algorithms
Graphical representation of different sorting algorithms on various input sizes.

Sorting algorithms differ from each other mainly based on the number of comparisons they make and time taken to sort the provided list of numbers.
In this project, most commonly used sorting algorithms like Bubble Sort, Insertion Sort, Selection Sort, Merge Sort and Quick Sort are implemented and tested on different sizes of input array generated randomly. Time taken and number of comparisons made by all the algorithms is recorded and plotted on a graph using `gnuplot`. 

Finally, a report is generated using `LaTeX`.

Size of input array is taken from 100 uptill 10000 incrementing by 100 everytime. If you want to change the size of input array, you can manually change it in all the C files.

Make sure you `texlive` and `gnuplot` installed in your system.

`sudo apt-get install texlive`
`sudo apt-get install gnuplot`

To generate graphs,

1. Compile all C files and execute them to generate the files containing the number of comparisons made and time taken.

2. To generate comparison graph, `gnuplot comparison_graph.plg`

3. To generate time graph, `gnuplot time_graph.plg`

(A `.eps` file is generated for both the plots and if you want the graph to be in a `.pdf` file then you can convert `.eps` to `.pdf` by `epstopdf <filename>.eps`)

4. To generate the modified report, `latex report.tex` or if you want in pdf then, `pdflatex report.tex`

# Chemistry Compound Geometry Analysis
## PIC 10C Final Project

I am a chemistry major student and I've been doing computational chemistry calculations in my research lab. I usually use Softwares like Gaussian 16.0 to calculate the reaction energies, reaction dynamics, and compound geometries. I want to make a C++ program that can simulate such calculations so I can run a quick calculation on my computer without sending it to the cluster. I also want to design it to eliminate unnecessary steps so I can obtain my output files faster than calculating them using the software. The program could include calculating atomic bond distance, degrees of unsaturation, and geometry analysis, etc. 

## Goals: 
Write a computer program to take a set of atomic symbols and Cartesian coordinates
for a collection of atoms and determine all possible interatomic distances. Assume
the coordinates are provided in Angstroms.

Additional features: calculation of Degrees of Unsaturation and IR analysis.

## Progress Log and Updates
### Day 1
* Chemical file formats are formats used to represent chemical structure records and its associated data fields. The different file formats includes CML (Chemical Markup Language), SDF (Structural Data format) PDB (Protein Data Bank), SMILES (Simplified Molecular Input Line Entry Specifications), etc. 
* For this project, I decided to use the `xyz file` format for my input files. These files have extention `.xyz`, and they have the total number of atoms and the xyz coordinates for each atom. I am mostly dealing with `xyz` files for my research, but I can also add functions like file convertions so that the program can read in other file types too. 
* Today, I build the `atom` class. I want it to store basic information for each atom in the compound, such as the coordinate, element name, bond interactions, properties, and the atomic number on the peridic table.  
* I noticed that it might be hard to give a name to each atom because there are so many of them. I will number them in the order they are read in. I might have to create a vector to store all the atoms later.
* I will continue building this class to make it more efficient when I input a bunch of atoms, maybe I should also make a `compound` class.

### Day 2
- I want to give more features to this project so I decided to also calculate the degree of unsaturation and IR analysis.
- Geometry analysis is kind of challenging for me since I have think of some functions to use to store values for a lot of numbers. I will reconsider about this choice and maybe change what I want to do. 
- New feature: Degrees of Unsaturation can be calculated directly from the input string of a molecular formula. The hard thing about this is that the characters can reapeat itself and there isn't necessary a number between all the characters. So I have to think of a way to collect all these info. Right now, I think that `enum` could work and I want to try to see if it is actually practical to use it. I learned from the first project about the usage of `enum` so I think it can apply here, let's see.

### Day 3
- I have been thinking a lot about how to handle the atom class, maybe I would just make it like the `elements` so they are easier to deal with? I will also need to think of good ways to skip certain characters and spaces in my `.xyz` file.
- Today I tried to define all the functions and tried that for a long time. Hopefully there could be fewer errors when the program is actually up and running.
- Also, I was having trouble on how to give IR analysis when the IR values are within mutiple ranges, right now I don't have good solutions for that.

### Day 4
- Today I made big progress in the building feature of Degrees of unsaturation(DU) calculations. I was able to solve the problem of repeated elements and added them up.
- I will look for ways to make these calculations more efficient and also start working on the IR feature. Maybe creating an output file for that, too?

### Day 5 
- I found so many issue in my codes and tried my best to tackle each of them. I eventually got to the point that everthing works fine. I found that sometimes my calculation results are off by a good amount, but I think I found that the problem is at where I placed the loop and have the declarition of variables.
- I added error input senario to make it not going to infinite loop if there is a wrong input or empty input. 
- Up to this point, `DU calculation`for the choice `b` is completely finished.




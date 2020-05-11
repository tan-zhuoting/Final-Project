# Chemistry Compound Geometry Analysis
## PIC 10C Final Project

I am a chemistry major student and I've been doing computational chemistry calculations in my research lab. I usually use Softwares like Gaussian 16.0 to calculate the reaction energies, reaction dynamics, and compound geometries. I want to make a C++ program that can simulate such calculations so I can run a quick calculation on my computer without sending it to the cluster. I also want to design it to eliminate unnecessary steps so I can obtain my output files faster than calculating them using the software. The program could include calculating atomic bond length, bond angles, energy and geometry analysis, etc. 

## Goals: 
Write a computer program to take a set of atomic symbols and Cartesian coordinates
for a collection of atoms and determine all possible interatomic distances. Assume
the coordinates are provided in Angstroms.

Additional features: Calculation of Degrees of Unsaturation and IR analysis.

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
- New feature: Degrees of Unsaturation can be calculated directly from the input string of a molecular formula. The hard thing about this is that the characters can reapeat itself and there isn't necessary a number between all the characters. So I have to think of a way to collect all these info. Right now, I think that 'enum' could work and I want to try to see if it is actually practical to use it. I learned from the first project about the usage of 'enum' so I think it can apply here, let's see.





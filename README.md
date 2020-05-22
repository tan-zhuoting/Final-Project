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

### Day 6
- I started coding for part c, IR analysis. I created the IR class and defined functions for it. Basically, it would perform a search within the given `Data.txt` document to find if the value lives within certain range. The search is perform by `find_first_of` and separating the data in the `Data.txt` file and change the string range data to integers.
- When looking for methods to perform this search, I learned many new things including the usage of `string::npos` and `assert`. There is also another way to do this by using `std::set`, which I did not fully understaqnd so I have decided to play it safe for now. I might change it if everything else woks out and I had extra time to experiment it.

### Day 7
- I decided to make `IR` a struct since I have never done that before, and it is pretty cool to try it. 
- I used vector as the container for collected information and everthing work out well as planned.
- However, I have encounter a problem that the console cannot display what I want, since there are some special characters and chemical symbols. So, my console ouput is like a mess right now. I have no idea how to sole this problem :(

### Day 8
- I added the new option of faster calculating of `IR`, and I am learning how to use std::set to perform the search.
- For this new option, I created another class particularly for `IR`
- The problem of console display still exists, I have tried many different ways but it is still a mess. There might be something wrong with my computer, becuase I tried it on my Dad's Macbook and it showed up just fine. I still want to change it though. 

### Day 9
- I alomst finished setting up for the `IRResolver` that can perform searches with set and shared pointer. I learned about keys, fat key and light key and the `C++14` way of using std::set `find`from the website https://en.cppreference.com/w/cpp/container/set/find and found that very useful
- Also, I learned how to use `std::less<>`, it is `a specialization of std::less with parameter and return type deduced`. Normally it is `std::less<xxxx>`, here I didn't use `xxxx` and want to deduce accroding the the actual code
- The main point of using `std::set` is to collect the overlaping section when inserting data, and split the overlapping section to non-overlapping and insert again

### Day 10
- Today I put to a test for the `IRResolver` but it did not work, I am not sure where the problem is and will do more research on why.
- My main idea for `IRResolver` is converting all the read in data to intervals that do not overlap, and then put it into `std::set`, the convert and insert is happening at the same time, and it is a recursive process
- I will also start thinking about how to deal with geometry analysis the same way as it is collecting the data.

### Day 11
- I finally figured out that my code does not work because visual studio cannot read `scanf`, I think that `sscanf` would be very useful for reading my formatted `data.txt` in reading string.
- I followed the tutorial online and fixed this isssue, but the issue of infinite loop is still not fixed, I will look into ways to do that.

### Day 12
- Today I fixed the issue of inifinite loop! It turned out to just be a small bug that I forgot to delete one of the while loop. 
- However, like the case in `IR`, the display on my console is still pretty bad that it does not show the special character. 
- We have covered how to use Qt, that makes me really want to make a Qt for my IR search function too. I want to try to do that if there is extra time left to enhance my project.

### Day 13
- After trying to ask the TA and my CS major friends, I have finally solved the display problem! Yay! 
- This is because my console does not show `UTF-8` characters. I solved this by adding `system("chcp 65001")` so that my console is showing the correct things now! I can finally use the IR feature correctly to predict functional groups.
- I created another repository to develop the Qt app for my `IRResolver` feature, but I am not sure how to add that to this repository, maybe I will just `colone` and `push` again to here, or I have read about the `sub-module` in git, it can basically create a sub-repository under this one. I will figure out how to do that. For now, I will just update my progress on the Qt app here.

### Day 14
- Today I started working on the Qt version `IRResolver`, I made some adjustment of the files but have not start designing the graphical interface yet. This is the baic implementation.
- I want to use let my Qt app to show the text the same as my C++ console ouput, and I am still learning how to do that as I am still not that good at Qt
- For now, choice `a` is still not useful for this C++ app, I will finish developing choice `a` after finishing this Qt app.